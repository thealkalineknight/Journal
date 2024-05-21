fill(255, 0, 255);

draw = function() {
    background(255, 255, 255);
    ellipse(mouseX, mouseY, 12, 12); 
    
    var track = mouseX + "," + mouseY;
    text(track, mouseX, mouseY);
};
