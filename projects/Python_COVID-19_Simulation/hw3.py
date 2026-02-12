# CS1210 HW3
#
# I certify that this file contains only my own work. I also certify
# that I have not shared the contents of this file with anyone in 
# any form.
#
def signed():
    return(["hcgamble"])

######################################################################
# This is my solution to hw3, which is now your template for HW3.  If
# you search the file for "TODO", you will see where you are expected
# to implement your changes.
#
# You will require one or more functions from the random module; here,
# we'll just import all of them.
from random import *

# You'll also need functions to check if files exist and are readable.
from os.path import isfile
from os import access, R_OK

######################################################################
# Specification: flip(p) flips a (weighted) coin. Returns True if a
# randomly generated float between 0 and 1 (inclusive) is less than or
# equal to the specified probability p.
#
def flip(p=0.5):
    return(random() <= p)

######################################################################
# Specification: binnedSample(k, N) produces a set (of size specified
# by k) of random integers selected without replacement from a range
# specified by N. The function constructs its result differently,
# depending on the types of k and N.
#
# If k and N are both ints, then we simply return a set of k randomly
# sampled ints in the range from 0 to N-1. So:
#   >>> binnedSample(3, 15)
#   {8, 9, 6}     # Note sampled from 0-14
#
# If N is a tuple and k is an int, we return a set of k randomly
# sampled ints from the bins represented by N. So:
#   >>> binnedSample(3, (5, 5, 5))
#   {4, 3, 14}    # Note sampled from 0-14
#
# Finally, if k and N are both tuples of the same length, we return a
# set of sum(k) randomly sampled ints taken from the bins represented
# by N.
#   >>> binnedSample((1, 1, 1), (5, 5, 5))
#   {2, 6, 11}    # Note 1 each from 0-4, 5-9, 10-14
#   >>> binnedSample((0, 0, 3), (5, 5, 5))
#   {14, 12, 10}  # Note all 3 from 10-14
#
# Your function should print a warning and return the empty list if
# the arguments are nonsensical.
#
def binnedSample(k, N):
    if isinstance(k, int) and isinstance(N, int):
        # k and N are both integers.
        return set(sample(range(N), min(k, N)))
    elif isinstance(k, int) and isinstance(N, tuple):
        # N is a tuple and k is an int.
        totalBins = []
        start = 0
        for binSize in N:
            totalBins.extend(range(start, start + binSize))
            start += binSize
        return set(sample(totalBins, min(k, len(totalBins))))
    elif isinstance(k, tuple) and isinstance(N, tuple) and len(k) == len(N):
        # Both k and N are tuples of the same length.
        result = set()
        start = 0
        for i in range(len(N)):
            binRange = range(start, start + N[i])
            result.update(sample(binRange, min(k[i], len(binRange))))
            start += N[i]
        return result
    else:
        print("Warning: Invalid statements for binnedSample.")
        return []
#print(binnedSample((1, 1), (5, 5, 5)))

######################################################################
# Specification: newPop(config) creates a new population agents. A
# population is an N-element tuple of agents, where each agent is
# represented by a dictionary with two entries. The 'state' of the
# agent (-1 <= s <= di+de) represents that agent's current disease
# condition, while the agent's 'vaccine' status (a Boolean) represents
# whether the agent has been vaccinated or not.
#
# Returns a tuple of agent dictionaries, where I agents, selected at
# random, are initially infected (disease state = di+de+1); all other
# agents are marked as susceptible (disease state = -1). 
#
# We also set the agent's vaccination state.  To get the behavior we
# want, we'll flip a weighted coin to determine whether the person is
# chooses to vaccinate, and, if so, set the effectiveness of that
# vaccine to a random value between 0 and 1. Those who elect to remain
# unvaccinated get an effectiveness of 0.
#
# A similar process is followed for masking; do they choose to mask,
# and if so, with what frequency? Non-masking agents get a frequency
# of 0.
#
# When selecting the I infected agents, we use a similar process to
# determine whether that agent is asymptomatic, and, if they are, we
# set their social isolation to 0 (they don't know to
# isolate). Otherwise, we'll set their social isolation depending on
# whether they choose to isolate, and, if so, with what frequency?
#
# We return the tuple, (pop, inf), where pop is a tuple of agents and
# inf is a set of agent indexes.
#
def newPop(config):
    # Helper function: returns a random value between 0-1 with
    # probability=p, 0.0 otherwise. In other words, this function
    # implements a filtering step where, with probability p, the agent
    # in question exhibits a behavior. It then returns how strongly
    # they exhibit that behavior (a probability) or, if they don't
    # exhibit the behavior at all, a 0.0. Useful for vaccination,
    # masking, and social isolation.
    def helper(p):
        return (random() if flip(p) else 0)
    # N and I variables
    N = config['N']
    I = config['I']

    # Determine the total number of agents and their types
    if isinstance(N, tuple):
        totalAgents = sum(N)
        agentTypes = []
        for i in range(len(N)):
            agentTypes += [i] * N[i]
    else:
        totalAgents = N
        agentTypes = [0] * totalAgents  # Default type 0 for all agents if N is not a tuple

    # Initialize the population
    pop = [{'state': -1, 'vaccine': helper(config['vp']), 'mask': helper(config['mp']), 'type': agentTypes[i]} for i in range(totalAgents)]

    # Select initial infecteds
    inf = binnedSample(I, N) if isinstance(I, int) else binnedSample(I, N)
    for i in inf:
        pop[i]['state'] = config['di'] + config['de'] + 1

        # Determine agent i's social isolation
        if flip(config['ap']):
            # Asymptomatic agents don't know to isolate.
            pop[i]['sociso'] = 0.0
        else:
            # Symptomatic agents choose to isolate or not, with
            # adherence set randomly.
            pop[i]['sociso'] = helper(config['ip'])

    # Return the population and the set of infecteds.
    return (pop, inf)



######################################################################
# Specification: update(pop, config) is called at the beginning of
# each simulation day to update each agent’s infection status. Agents
# with infection state 1 (i.e., at the end of their infectious period)
# are set to 0 (recovered state) with probability rp, and otherwise
# set to -1 (susceptible state). All other infectious agents have
# their infection state reduced by 1. Returns the set of active
# infections remaining.
#
def update(pop, inf, config):
    # Agents recovered or susceptible this round
    drop = set()
    for i in inf:
        if pop[i]['state'] == 1: 
            # Newly susceptible with p=(1-rp), else recovered. To
            # avoid 0's Boolean interpretation, we're using 1-rp so
            # that we can return -1 and default to 0. Might be more
            # easily interpretable using an explicit if/else here.
            pop[i]['state'] = (flip(1-config['rp']) and -1) or 0
            # Add to drop set.
            drop.add(i)
        elif pop[i]['state'] > 0:
            # Decrement state if still infectious
            pop[i]['state'] = pop[i]['state']-1
    # Cleanup infected set
    inf = inf - drop
    return(inf)

######################################################################
# Specification: readConfig(cfile) takes a file name (a string),
# checks to see if it exists, then opens and reads the simulation
# configuration variables from the file.
#
def readConfig(cfile):
    # Here's a little helper function to help convert values from the
    # configuration file into Booleans, integers, or floats (the only
    # types we have to worry about here).
    #
    # TODO: extend to return tuples of comma-separated values where
    # appropriate.
    def cast(value):
        if isinstance(value, str) and value.lower() in ("true", "false"):
            # Value is a Boolean
            return(value.lower().capitalize() == 'True')
        elif value.isnumeric():
            # Value is an integer
            return(int(value))
        elif (''.join(value.split('.'))).isnumeric():
            # Value is a float
            return(float(value))
        elif ',' in value:
            # Value is a tuple
            return tuple(map(int, value.split(',')))
        else:
            print("Unexpected value '{}' in configuration file.".format(value))
        return(None)

    # Establish the default configuration. This mimics what's in the
    # assignment handout, but I've also picked a few more defaults for
    # the newly added factors vp, mp, ap, and ip. Note also that I'm
    # returning a random seed (returned by seed() with no arguments)
    # in the event that there is no seed value in the configuration
    # file. In this way, absence of a specified seed yields a random
    # one, and I don't have to implement any conditional behavior
    # based on whether a seed is specified or not.
    config={'N': 100, 'I': 1, 'm': 4, 'de': 3, 'di': 5, 'tpe': 0.01, 'tpi': 0.02, 'rp':0.5,
            'vp': 0.9, 'mp': 0.3, 'ap': 0.3, 'ip': 0.4, 'max': 100, 'verbose': False, 'seed': seed()}

    # Check if config file exists
    if isfile(cfile) and access(cfile, R_OK):
         # Parse the config file. Here, the config file is
         # highly constrained. So a few "strips" and "splits" can get
         # you pretty much all of the way there.
        with open(cfile, 'r') as file:
            for line in file:
                # Skip any blank or comment lines
                if line.strip() == '' or line.lstrip()[0] == '#':
                    continue
                line=[ element.strip() for element in line.split(':') ]
                # Parse configuration (anything between ':' and '#' or
                # EOL).
                #
                # TODO: make sure you also allow integers as legal
                # keys, but only if they are being used to provide
                # mixing parameters for a population subgroup.
                if line[0] in config.keys():
                    config[line[0]] = cast(line[1].split('#')[0].strip())
                elif type(config['N']) == tuple and line[0].strip().isdigit():
                    if int(line[0]) in range(len(config['N'])):
                        config[int(line[0])] = cast(line[1].split('#')[0].strip())
                    else:
                        print("Unexpected line '{}' in configuration file.".format(line[0]))
    # Return configuration
    return(config)
#print(readConfig('hw3.cfg'))
#print(newPop(readConfig('hw3.cfg')))

######################################################################
# Specification: sim(cfile='hw3.cfg') returns a list of integers,
# where each integer represents the number of infections on the
# corresponding simulation day (i.e., the pandemic curve). There are a
# large number of parameters, all with default values:
#   N: number of agents in the simulation
#   I: number of infections during simulation; initially,
#      the number of infected agents on day 1.
#   m: mixing parameter is the max number of daily interactions initiated
#      by a given agent: randint(0,m) generates a given day's tally.
#   vp: probability that an agent has been vaccinated
#   tp: tuple of transmission probabilities; first value corresponds
#       to the shedding rate while exposed, the second to the shedding
#       rate while infected (generally higher).
#   de: number of days agent remains in exposed state
#   di: number of days agent remains in infected state
#   rp: probability of recovery (as opposed to becoming susceptible again)
#   max: failsafe simulation time limit, in days
#   config['verbose']: Boolean value toggles user feedback
#
# A few more words about how we use our simple infection model (see
# Carrat et al, 2008).  People are exposed for de days (the exposed
# period), then infected for di additional days (the infected period):
# they are infectious (that is, they can infect others) while they are
# either exposed or infected.  We'll use a "daily countdown" to model
# each agent's disease state.
#
# Agents generally start the simulation as susceptible, that is, a
# status of -1. If they are infected on day t, we assume their exposed
# period runs for de days starting the next day, t+1, and then their
# infected period starts on day t+de and runs for di days. At the
# beginning of each day, update() updates each agent's infection
# status.
#
# Carrat et al. (2008) indicate E~2 and I~7 for influenza, so let's
# see a concrete example how this works. At infection on dy t, we set
# the agent's state to di+de+1 (the extra 1 ensures the agent enters
# the infectious range on the day following infectoin, after the
# beginning-of-day status update). After the infection has run its
# course, update() flips a coin to decide if the agent is now immune
# (recovered, 0) or becomes susceptible once again (-1).
#
# If I=7, E=2:
#   SUS REC                   I    I+E I+E+1
#     |  |                    |     |   |
#    -1  0  1  2  3  4  5  6  7  8  9  10
#     .  . |===================||====| .   <= days
#
def sim(cfile='hw3.cfg'):
    # Specification: susceptible(i) returns True if and only if agent
    # i is susceptible (state counter == -1 and neither vaccination or
    # masking effective).
    #
    def susceptible(i):
        return(pop[i]['state'] == -1 and not flip(pop[i]['vaccine']) and not flip(pop[i]['mask']))

    # Specification: exposed(i) returns True if and only if agent i is
    # exposed (has state counter between di and di+de).
    #
    def exposed(i):
        return(config['di'] < pop[i]['state'] <= config['di']+config['de'])

    # Specification: infected(i) returns True if and only if agent i
    # is exposed (has state counter between 0 and di).
    #
    def infected(i):
        return(0 < pop[i]['state'] <= config['di'])

    # Specification: infectious(i) returns True if and only if agent i
    # is infectious (e.g., either infected or exposed) and not masked.
    #
    def infectious(i):
        return(0 < pop[i]['state'] <= config['di']+config['de'] and not flip(pop[i]['mask']) and not flip(pop[i]['sociso']))

    # Specification: recovered(i) returns True if and only if agent i
    # is in the recovered state.
    #
    def recovered(i):
        return(pop[i]['state'] == 0)

    # Read the config file first.
    config = readConfig(cfile)

    # Set the seed: the default sets the seed to start time.
    if 'seed' in config:
        seed(config['seed'])

    # Create agents: returns a tuple of agent records and a set of
    # infected agent indexes into pop.
    pop, inf = newPop(config)

    # Good to go, now run the simulation. We'll use totinf to keep
    # track of all infection events.
    totinf = len(inf)
    
    # Similarly, we’ll use curve, a list, to keep track of how many
    # infecteds there are each day, starting from day 0.
    curve = [totinf]

    # Run the simulation (i.e., keep looping) while there are
    # infecteds remaining (that is, while curve[-1] > 0) or until you
    # hit the failsafe number of rounds limit, max. 
    rounds = 0
    while rounds < config['max']:
        # Beginning-of-day agent status update: returns the number of
        # active infections on the new day, which we append to the
        # curve list.
        inf = update(pop, inf, config)
        curve.append(len(inf))

        # If config['verbose'] is True, show user feedback.
        if config['verbose']:
            print("Day {}: {} of {} agents infected.".format(len(curve)-1, curve[-1], len(pop)))

        # Quit the simulation if there are no infections left.
        if curve[-1] == 0:
            print("Pandemic extinguished: {} days, {} infecteds, attack rate is {:3.1f}%.".format(len(curve)-1, totinf, (100*totinf)/len(pop)))
            break

        # For each infected agent, sample the population to find who
        # they mix with, and then flip a coin to determine if a new
        # infection occurs.  For each new infection, update the
        # appropriate agent's status as well as totinf, the total
        # infection count.
        newInf = set()
        for i in inf:
            # Generate a list encounters by random sampling
            # without replacement (see Python documentation).
            #
            # TODO: here you will need to handle the case where there
            # are subgroup mixing parameters. Depending on i's group,
            # you will want to skew the selection of the
            # randint(0,config['m']) interacting agents from the
            # appropriate subgroups. It's a good chance to use
            # binnedSample() again, with appropriate arguments.
            sample = []
            if type(config['N']) == int:
                sample = sample(range(len(pop)), randint(0, config['m']))
            elif type(config['N']) == tuple:
                xM = randint(0, config['m'])
                sample = binnedSample(tuple([round((x/100)*xM) for x in config[pop[i]['type']]]), config['N'])
            for j in sample:
                # Is there a new infection? This depends on current
                # disease state as well as j's masking and vaccination
                # status and i's masking and social isolation status.
                if infectious(i) and susceptible(j) and ((exposed(i) and flip(config['tpe'])) or (infected(i) and flip(config['tpi']))):
                    # Update totinf, the total infection event count.
                    totinf = totinf+1
                    pop[j]['state'] = config['di']+config['de']+1

                    # Determine newly infected agent j's social
                    # isolation, which will be used to determine how
                    # effective an infectious agent he will be. This
                    # mirrors what we did for initial infecteds in
                    # newPop() but unfortunately I haven't got that
                    # handy helper function available here! Since this
                    # is the only place I use it within this funcion,
                    # I'll just paste the guts of the helper function
                    # in here directlyh.
                    if flip(config['ap']):
                        pop[j]['sociso'] = 0
                    else:
                        pop[j]['sociso'] = ((flip(config['ip']) and random()) or 0)

                    # If config['verbose'] is True, show user feedback.
                    if config['verbose']:
                        print("  Agent {} infected by agent {} [si={}].".format(j, i, pop[j]['sociso']))
                    # Keep track of new infections
                    newInf.add(j)

        # Add any new infecteds to infected set
        inf.update(newInf)
        # Update failsafe simulation limit
        rounds = rounds + 1
    else:
        print("Pandemic persists: {} days, {} infecteds, attack rate is {:3.1f}%.".format(len(curve)-1, totinf, (100*totinf)/len(pop)))
    # Return simulation curve.
    return(curve)
print(sim(cfile='hw3.cfg'))