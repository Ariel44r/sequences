#include<iostream>
#include<math.h>
#include"sequences.h"

using namespace std;


//Main_Program
int main()
{
	int N;
	cin >> N;
	functions seq1(N),seq2(N);
	seq1.Sampling ();
	seq2.Sampling ();
	functions seq3 = seq1 + seq2;
	functions seq4 = seq1 - seq2;
	functions seq5 = seq1 * seq2;
	functions seq6 = seq1 / seq2;
	functions seq7 = seq1 ^ seq2;
	functions seq8 = seq1 > seq1;
	seq3.Print ();
	seq4.Print ();
	seq5.Print ();
	seq6.Print ();
	seq7.Print ();
	seq8.Print ();
	cin.get();
	cin.get();
	return 0;
}
