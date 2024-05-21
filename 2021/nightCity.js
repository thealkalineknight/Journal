var xPos = 0;
var yPos = 0;

var xPos2 = 400;
var yPos2 = 250;

draw = function() {
    xPos = xPos + 50;
    yPos = yPos + 50;
    
    background(11, 18, 66);
    
    noStroke();
    
    fill(215, 242, 237);
    ellipse(100, 30, 10, 10);
    ellipse(190, 100, 10, 10);
    ellipse(240, 90, 10, 10);
    ellipse(20, 110, 10, 10);
    ellipse(390, 10, 10, 10);
    ellipse(340, 96, 10, 10);
    ellipse(290, 26, 10, 10);
    
    ellipse(xPos, yPos, 10, 10);
    
    fill(38, 34, 34);
    rect(100, 300, 90, 100);
    rect(200, 250, 90, 150);
    rect(300, 320, 90, 90);
    rect(0, 230, 90, 200);
    
    xPos2 = xPos2 - 5;
    
    fill(400, 400, 400);
    ellipse(xPos2, yPos2, 70, 10);
    rect(xPos2 - 7, yPos2, 10, 30);
    rect(xPos2 - 7, yPos2 - 26, 10, 30);
    rect(xPos2 + 25, yPos2, 5, 10);
    rect(xPos2 +25, yPos2 - 10, 5, 10);
};
