#include "food.h"

Food::Food() {
    // Image image = LoadImage("Graphics/food.png");
    // texture = LoadTextureFromImage(image);
    // UnloadImage(image);
    position = GenerateRandomCell();
}

Food::~Food() {
    // UnloadTexture(texture);
}

void Food::Draw() {
    // DrawRectangle(position.x * st.cellSize, position.y * st.cellSize, st.cellSize, st.cellSize, st.green);
    // DrawTexture(texture, position.x * st.cellSize, position.y * st.cellSize, WHITE);
}

Vector2 Food::GenerateRandomCell() {
    float x = GetRandomValue(0, st.cellCount - 1);
    float y = GetRandomValue(0, st.cellCount - 1);
    return Vector2{ x, y };
}