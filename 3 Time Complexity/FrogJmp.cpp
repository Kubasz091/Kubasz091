int solution(int X, int Y, int D) {
    return ((Y - X) / D) + (bool)((Y - X) % D);
}