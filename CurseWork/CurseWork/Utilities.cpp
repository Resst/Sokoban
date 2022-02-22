struct Vector2{
	int x;
	int y;
	void translate(int X, int Y) {
		x += X;
		y += Y;
	}
	void scale(int scaleX, int scaleY){
		x *= scaleX;
		y *= scaleY;
	}
	void set(int X, int Y) {
		x = X;
		y = Y;
	}
	bool equal(int X, int Y) {
		return (x == X) && (y == Y);
	}
};