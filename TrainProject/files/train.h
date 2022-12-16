class train {
public:

	static void lastStroller(float box,
						 int front, int back,
						 int bottomWindow, int topWindow, int centerWindow, int rightAndLeftWindow,
						 int floorStroller, int ceilStroller,
						 int bottomWindowOut, int topWindowOut, int backTrainOut
						 );

	static void stroller(float box,
						 int front, int back,
						 int bottomWindow, int topWindow, int centerWindow, int rightAndLeftWindow,
						 int floorStroller, int ceilStroller,
						 int bottomWindowOut, int topWindowOut
						 );

	static void firstStroller(float box,
						 int front, int back,
						 int bottomWindow, int topWindow, int centerWindow, int rightAndLeftWindow,
						 int floorStroller, int ceilStroller,
						 int bottomWindowOut, int topWindowOut 
						 );
};