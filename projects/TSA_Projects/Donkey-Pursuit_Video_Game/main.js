//https://drive.google.com/file/d/1qJp07f8yUDBJMufCUenqekxy8qzKS-KN/view?usp=share_link
// creates the sprites/variables
var target = createSprite(200, 200);
target.setAnimation("target.png");
target.scale = 3;
var fence = createSprite(200, 200);
fence.scale = 4;
var partyfence = createSprite(200, 200);
partyfence.setAnimation("partyfence.png");
partyfence.scale = 4;
partyfence.visible = false;
var crownfence = createSprite(200, 200);
crownfence.setAnimation("crownfence.png");
crownfence.scale = 4;
crownfence.visible = false;
var donkey = createSprite(randomNumber(75, 335), randomNumber(75, 335));
donkey.setAnimation("donkey.png");
donkey.setCollider("circle", 0, 0, 5);
donkey.scale = 1.3;
var cowboydonkey = createSprite(randomNumber(75, 335), randomNumber(75, 335));
cowboydonkey.setAnimation("cowboydonkey.png");
cowboydonkey.setCollider("circle", 0, 0, 5);
cowboydonkey.scale = 1.3;
cowboydonkey.visible = false;
var partydonkey = createSprite(randomNumber(75, 335), randomNumber(75, 335));
partydonkey.setAnimation("partydonkey.png");
partydonkey.setCollider("circle", 0, 0, 5);
partydonkey.scale = 1.3;
partydonkey.visible = false;
var crowndonkey = createSprite(randomNumber(75, 335), randomNumber(75, 335));
crowndonkey.setAnimation("crowndonkey.png");
crowndonkey.setCollider("circle", 0, 0, 5);
crowndonkey.scale = 1.3;
crowndonkey.visible = false;
var tail = createSprite(200, 200);
tail.setAnimation("tail.png");
tail.setCollider("circle", 1, 1, 20);
tail.scale = 1.4;
var partytail = createSprite(200, 200);
partytail.setAnimation("partytail.png");
partytail.setCollider("circle", 1, 1, 20);
partytail.scale = 1.4;
partytail.visible = false;
var crowntail = createSprite(200, 200);
crowntail.setAnimation("crowntail.png");
crowntail.setCollider("circle", 1, 1, 20);
crowntail.scale = 1.4;
crowntail.visible = false;
var scissors1 = createSprite(randomNumber(0, 400), randomNumber(0, 10));
scissors1.setAnimation("scissors1.png");
scissors1.velocityY = 2;
scissors1.scale = 0.7;
scissors1.setCollider("circle", 1, 1, 20);
var scissors2 = createSprite(randomNumber(0, 400), randomNumber(380, 400));
scissors2.setAnimation("scissors2.png");
scissors2.velocityY = -2;
scissors2.scale = 0.7;
scissors2.setCollider("circle", 1, 1, 20);
var scissors3 = createSprite(randomNumber(0, 10), randomNumber(0, 400));
scissors3.setAnimation("scissors3.png");
scissors3.velocityX = 2;
scissors3.scale = 0.7;
scissors3.setCollider("circle", 1, 1, 20);
var scissors4 = createSprite(randomNumber(390, 400), randomNumber(0, 400));
scissors4.setAnimation("scissors4.png");
scissors4.velocityX = -2;
scissors4.scale = 0.7;
scissors4.setCollider("circle", 1, 1, 20);
var cake = createSprite(210, 290);
cake.setAnimation("cake.png");
cake.visible = false;
var score = 0;
var dieText = "please reload the screen";
var dieText2 = "(CTRL+'R' or CMD+'R')";
//displays the score rectangle
function displayScore() {
  fill(rgb(210, 190, 132));
  rect(30, 27, 102, 30);
  rect(185, 27, 185, 38);
  textSize(20);
  noStroke();
  fill("black");
  text("Score:"+score, 35, 48);
  fill(rgb(210, 190, 132));
  textSize(15);
  noStroke();
  fill("black");
  text("Spacebar for Directions", 190, 51);
  textSize(13);
}
//displays the directions rectangle
function rules() {
   if (keyDown("space")) {
    target.visible = false;
    donkey.visible = false;
    tail.visible = false;
    fence.visible = false;
    scissors1.visible = false;
    scissors1.setVelocity(0, 0);
    scissors2.visible = false;
    scissors2.setVelocity(0, 0);
    scissors3.visible = false;
    scissors3.setVelocity(0, 0);
    scissors4.visible = false;
    scissors4.setVelocity(0, 0);
    stroke("black");
    fill(rgb(24, 21, 21));
    rect(0, 0, 400, 600);
    noStroke();
    fill("white");
    textSize(20);
    text("RULES:", 163, 50);
    textSize(12);
    text("Pin the tail on the donkey!", 115, 95);
    text("Use the arrow keys to move.", 107, 140);
    text("Don't let the scissors hit the tail!", 98, 188);
    text("Every 20 points the level will change.", 82, 230);
    text("Game over at 60 points.", 125, 271);
   }
   if (keyWentUp("space")) {
     target.visible = true;
     donkey.visible = true;
    tail.visible = true;
    fence.visible = true;
    scissors1.visible = true;
     scissors1.velocityY = 2;
    scissors2.visible = true;
     scissors2.velocityY = -2;
    scissors3.visible = true;
     scissors3.velocityX = 2;
    scissors4.visible = true;
     scissors4.velocityX = -2;
   }
}
//Calls all the functions and allows the game to fully run
function draw() {
  fence.setAnimation("fence.png");
  background(rgb(165, 149, 129));
  textSize(30);
  textFont("verdana");
  fill(rgb(50, 46, 46));
  text("PIN THE TAIL", 107, 97);
  text("ON THE DONKEY", 75, 330);
  displayScore();
  rules();
  if (keyDown("up")) {
    tail.y = tail.y - 2.7;
  }
  if (keyDown("down")) {
    tail.y = tail.y + 2.7;
  }
  if (keyDown("left")) {
    tail.x = tail.x - 2.7;
  }
  if (keyDown("right")) {
    tail.x = tail.x + 2.7;
  }
  nextLevel();
  nextDonkey();
  scissorsCome();
  tailComes();
  dieColor();
  die();
  drawSprites();
}
//makes the scissors move across the screen
function scissorsCome() {
  if (scissors1.y>400 ) {
      scissors1.x = randomNumber(0, 400);
      scissors1.y = randomNumber(0, 10);
      scissors1.velocityY = 2.8;
    }
  if (scissors2.y < 0) {
      scissors2.x = randomNumber(0, 400);
      scissors2.y = randomNumber(390, 400);
      scissors2.velocityY = -2.8;
    }
  if (scissors3.x > 400 ) {
      scissors3.x = randomNumber(0, 10);
      scissors3.y = randomNumber(0, 400);
      scissors3.velocityX = 2.8;
    }
  if (scissors4.x < 0) {
      scissors4.x = randomNumber(390, 400);
      scissors4.y = randomNumber(0, 400);
      scissors4.velocityX = -2.8;
    }
  if (score > -1) {
      scissors4.rotationSpeed = 7;
      scissors3.rotationSpeed = 7;
      scissors2.rotationSpeed = 7;
      scissors1.rotationSpeed = 7;
    }
}
//allows the tail to collide with the donkey and add to the score
function tailComes() {
  if (tail.collide(donkey)) {
    score = score + 1;
    donkey.x = randomNumber(55, 355);
    donkey.y = randomNumber(55, 355);
  }
}
//destroys all sprites and is called when the scissors collide with the tail
function tailCut() {
  scissors1.destroy();
  scissors2.destroy();
  scissors3.destroy();
  scissors4.destroy();
  donkey.destroy();
  target.destroy();
  fence.destroy();
  tail.destroy();
  score = "-";
}
//Game over function when tail collides with the scissors
function die() {
  if (tail.collide(scissors1)) {
    tailCut();
      }
  if (tail.collide(scissors2)) {
      tailCut();
    }
  if (tail.collide(scissors3)) {
      tailCut();
    }
  if (tail.collide(scissors4)) {
      tailCut();
    }
}
//makes the game over screen
function dieColor() {
  if (score == "-") {
    background("black");
    fill("white");
    textSize(35);
    text("DEATH.", 145, 195);
    textSize(18);
    text(dieText, 95, 230);
    text(dieText2, 100, 255);
  }
}
//changes the level of the game when you hit a certain score
function nextLevel() {
  if (score > 19) {
    background(rgb(195, 173, 192));
    textSize(30);
  textFont("verdana");
  fill(rgb(50, 46, 46));
  text("PIN THE TAIL", 107, 97);
  text("PARTY LEVEL", 107, 330);
    cowboydonkey.setAnimation("partydonkey.png");
    fence.setAnimation("partyfence.png");
    target.setAnimation("partytarget.png");
    tail.setAnimation("partytail.png");
    fill(rgb(210, 190, 132));
  rect(30, 27, 102, 30);
  textSize(20);
  noStroke();
  fill("black");
  text("Score:"+score, 35, 48);
  }
 if (score > 39) {
    background(rgb(166, 176, 99));
    textSize(30);
  textFont("verdana");
  fill(rgb(50, 46, 46));
  text("PIN THE TAIL", 107, 97);
  text("ROYALTY LEVEL", 90, 330);
    donkey.setAnimation("crowndonkey.png");
    fence.setAnimation("crownfence.png");
    target.setAnimation("crowntarget.png");
    tail.setAnimation("crowntail.png");
    fill(rgb(210, 190, 132));
  rect(30, 27, 102, 30);
  textSize(20);
  noStroke();
  fill("black");
  text("Score:"+score, 35, 48);
   }
  if (score > 59) {
    fence.destroy();
    target.destroy();
    tail.destroy();
    donkey.destroy();
    scissors1.destroy();
    scissors2.destroy();
    scissors3.destroy();
    scissors4.destroy();
    background("black");
    textSize(23);
    fill("white");
    text("YOU WIN!", 150, 130);
    text("Congratulations! Here's a cake.", 27, 200);
    cake.visible = true;
  }
}
//changes the donkey when you hit a certain score
function nextDonkey() {
  if (score > 9 && score < 20) {
    donkey.setAnimation("cowboydonkey.png");
    textSize(15);
    fill(rgb(50, 46, 46));
    text("yeehaw", 172, 350);
  }
  if (score > 19 && score < 40) {
    donkey.setAnimation("partydonkey.png");
  }
  if (score > 39 && score < 60) {
    donkey.setAnimation("crowndonkey.png");
  }
}
