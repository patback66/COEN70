class statistician {
	private:
		long _length;
		double _lastNumber;
		double _sum;
		double _smallest;
		double _largest;
	public:
		/*
		Constructor
		*/
		statistician();

		/*
		Update statistic with given "number"
		*/
		void next_number(double number);

		/*
		Get the last number added to statistician
		*/
		double getLastNumber();

		/*
		Get the largest number that has been added to statistician
		*/
		double getLargestNumber();

		/*
		Get the smallest number that has been added to statistician
		*/
		double getSmallestNumber();

		/*
		Get the mean for all values in statistician
		*/
		double getMean();

		/*
		Get the sum for all values in statistician
		*/
		double getSum();

		/*
		Get the length of statistician (Number of items added to statistician)
		*/
		long length();

		/*
		Reset statistician to initial state
		*/
		void reset();

		/*
		Overload operator +
		*/
		statistician operator+ (statistician b);
};