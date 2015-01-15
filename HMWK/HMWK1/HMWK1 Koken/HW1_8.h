class quadratic {
	private:
		double _a;
		double _b;
		double _c;
		/*
		Internal function used to calculate number of real roots and store answers into given pointer.
		*/
		int _numberOfRealRoots(double* sol1, double* sol2);
	public:
		/*
		Constructor
		*/
		quadratic(double a = 0, double b = 0, double c = 0);
		
		/*
		Update coeffcient in the quadratic formula
		*/
		void updateCoeffcients(double a, double b, double c);
		
		/*
		Get value of "a" in quadratic formula
		*/
		double getA();
		
		/*
		Get value of "b" in quadratic formula
		*/
		double getB();
		
		/*
		Get value of "b" in quadratic formula
		*/
		double getC();
		
		/*
		Evaluate quadratic formula with given "x"
		*/
		double evaluate(double x);
		
		/*
		Get number of real roots for current quadratic formula
		*/
		int numberOfRealRoots();
		
		/*
		Get the smaller solution for current quadratic formula
		*/
		double smallerSolution();
		
		/*
		Get the larger solution for current quadratic formula
		*/
		double largerSolution();
		
		/*
		Overload operator +
		*/
		friend quadratic operator+ (const quadratic& q1, const quadratic& q2);
		
		/*
		Overload operator * for multiply with a number
		*/
		friend quadratic operator * (double r, const quadratic& q);
};