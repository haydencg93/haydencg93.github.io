/*These variables get the information from the "Sports
Spanish Translations" data table.*/
var englishTransList = getColumn("Sports Spanish Translations", "English");
var idList = getColumn("Sports Spanish Translations", "id");
var filteredEnglishTransList = [];
var masculineList = ["el campo través", "el básquetbol", "el béisbol", "el fútbol americano", "el fútbol", "el hockey", "el tenis", "el fútbol", "el sofbol", "el lacrosse", "el rugby", "el golf", "los bolos", "el tiro con arco", "el baile"];
var feminineList = ["la natacíon", "la pista", "la lucha"];
onEvent("mainRandomGenButton", "click", function() {
  filter();
  updateScreen();
});
/*This function will filter through to get a random result for a
possible sport to translate if you want it to.*/
function filter(){
  for(var i=0; i<englishTransList.length; i++){
    if((idList[i]) <= 18){
      appendItem(filteredEnglishTransList, englishTransList[i]);
      console.log("filtered");
    }
  }
}
/*This function updates the screen/text area to the random sport
assigned.*/
function updateScreen(){
  var index = randomNumber(0, filteredEnglishTransList.length-1);
  setText("mainRandomGenOutput", filteredEnglishTransList[index]);
  console.log("update");
}
/*The onEvent will look at the dropbdown the whole time and
whenever the dropbdown changes, it'll recognize that it has
changed and will get the text from the dropdown when it changes.
This information will be stored as "eng" and will be used in the
function below.*/
onEvent("mainTransDrop", "change", function(){
  filter1(getText("mainTransDrop"), getText("mainGenDrop"));
  console.log("filter1");
});
onEvent("mainGenDrop", "change", function(){
  filter1(getText("mainTransDrop"), getText("mainGenDrop"));
  console.log("filter1");
});
/*This function will take the input that the onEvent grabbed from
the dropdown and will use "eng" to determine if it equals a certain
sport. Whatever sport that it is, it'll output the Spanish 
translation.*/
function filter1(eng, gen) {
  if (eng == "Swimming") {
    setText("mainTransOutput", "la natación");
    console.log("eng/swim");
  } else if (eng == "Track") {
    setText("mainTransOutput", "la pista");
    console.log("eng/track");
  } else if (eng == "Cross Country") {
    setText("mainTransOutput", "el campo través");
    console.log("eng/xc");
  } else if (eng == "Basketball") {
    setText("mainTransOutput", "el básquetbol");
    console.log("eng/basket");
  } else if (eng == "Baseball") {
    setText("mainTransOutput", "el béisbol");
    console.log("eng/base");
  } else if (eng == "Wrestling") {
    setText("mainTransOutput", "la lucha");
    console.log("eng/wrestle");
  } else if (eng == "Football") {
    setText("mainTransOutput", "el fútbol americano");
    console.log("eng/foot");
  } else if (eng == "Volleyball") {
    setText("mainTransOutput", "el voleibol");
    console.log("eng/volley");
  } else if (eng == "Hockey") {
    setText("mainTransOutput", "el hockey");
    console.log("eng/hockey");
  } else if ((eng == "Tennis")) {
    setText("mainTransOutput", "el tenis");
    console.log("eng/tennis");
  } else if ((eng == "Soccer")) {
    setText("mainTransOutput", "el fútbol");
    console.log("eng/soccer");
  } else if ((eng == "Softball")) {
    setText("mainTransOutput", "el sofbol");
    console.log("eng/soft");
  } else if ((eng == "Lacrosse")) {
    setText("mainTransOutput", "el lacrosse");
    console.log("eng/lacrosse");
  } else if ((eng == "Rugby")) {
    setText("mainTransOutput", "el rugby");
    console.log("eng/rugby");
  } else if ((eng == "Golf")) {
    setText("mainTransOutput", "el golf");
    console.log("eng/golf");
  } else if ((eng == "Bowling")) {
    setText("mainTransOutput", "los bolos");
    console.log("eng/bowl");
  } else if ((eng == "Archery")) {
    setText("mainTransOutput", "el tiro con arco");
    console.log("eng/archery");
  } else if ((eng == "Dance")) {
    setText("mainTransOutput", "el baile");
    console.log("eng/dance");
  }
  if (gen == "Feminine") {
    setText("mainGenOutput", feminineList.join(", "));
    console.log("gen/feminine");
  } else if (gen == "Masculine") {
    setText("mainGenOutput", masculineList.join(", "));
    console.log("gen/masculine");
  }
}
