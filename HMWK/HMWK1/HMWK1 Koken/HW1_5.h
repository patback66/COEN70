class position {
	private:
		double _x;
		double _y;
		double _z;
	public:
		struct point {
			double x;
			double y;
			double z;
		};
		
		enum Axis
		{
			X, Y, Z
		};
		
		/*
		Constructor
		*/
		position(double x = 0, double y = 0, double z = 0);
		
		/*
		Setter for position
		*/
		void setPosition(double x, double y, double z);
		
		/*
		Get the coordinates stored in position object
		*/
		point getCoordinates();
		
		/*
		Shift the position by "length" on given axis
		*/
		void shift(Axis axis, double length);
		
		/*
		Rotate the position by "angle" on given axis
		*/
		void rotate(Axis axis, double angle);
};