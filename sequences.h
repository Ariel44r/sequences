#include<iostream>
#include<math.h>
#include"COMPLEXLIB.h"

using namespace std;

class functions
{
	public:
		int N;
		double *sequence;
	public:

//Constructor
	functions (const int N)
	{
		this -> N = N;
		sequence = new double [N-1];
		for (int l=0;l<N;l++)
		{
			sequence[l] = 0;
		}
	}

//Sampling_Function
	void Sampling ()
	{
		for (int j=0;j<N;j++)
		{
			cin >> sequence [j];
		}
	}

//Print_Sequence
	void Print ()
	{
		cout << "f = { ";
		for (int k=0;k<N;k++)
		{
			cout << sequence [k];
			if (k<N-1)
			{
				cout << ",";
			}
		}
		cout << "\t}"<<endl;
	}

//Destructor
	~functions () {}
};

//Operator_Overload_+_(Sum)
functions& operator +(const functions &p1,const functions &p2)
{
	int NN = p1.N;
	functions *comm;
	comm = new functions(NN);
	for (int k=0;k<NN;k++)
	{
		comm -> sequence[k]= p1.sequence[k] + p2.sequence[k];
	}
	return *(comm);
}

//Operator_Overload_-_(Substract)
functions& operator -(const functions &p1,const functions &p2)
{
	int NN = p1.N;
	functions *comm;
	comm = new functions(NN);
	for (int k=0;k<NN;k++)
	{
		comm -> sequence[k]= p1.sequence[k] - p2.sequence[k];
	}
	return *(comm);
}

//Operator_Overload_*_(Product)
functions& operator *(const functions &p1,const functions &p2)
{
	int NN = p1.N;
	functions *comm;
	comm = new functions(NN);
	for (int k=0;k<NN;k++)
	{
		comm -> sequence[k]= p1.sequence[k] * p2.sequence[k];
	}
	return *(comm);
}

//Operator_Overload_/_(Division)
functions& operator /(const functions &p1,const functions &p2)
{
	int NN = p1.N;
	functions *comm;
	comm = new functions(NN);
	for (int k=0;k<NN;k++)
	{
		comm -> sequence[k]= p1.sequence[k] / p2.sequence[k];
	}
	return *(comm);
}

//Operator_Overload_^_(Convolution)
functions& operator ^(const functions &p1,const functions &p2)
{
	int NN = p1.N + p2.N;
	functions *comm;
	comm = new functions(NN-1);
	for (int n=0;n<NN-1;n++)
	{
		for (int k=0;k<p1.N;k++)
		{
			if ((n-k>=0)&&(n-k<p1.N))
			{
				comm -> sequence[n] = comm -> sequence[n] + p1.sequence[n-k] * p2.sequence[k];
			}
		}
	}
	return *(comm);
}

//Operator_Overload_>_(Discrete_Fourier_Transform)
functions& operator >(const functions &p1,const functions &p2)
{
	int NN = p1.N;
	functions *comm;
	comm = new functions(NN);
	complex movw(0,0);
	complex movwf(0,0);
	double pi = 3.141592654;
	double Wn = 2 * pi / NN;
	for (int k=0;k<NN;k++)
	{
		movwf.Evaluate(0,0);
		for(int j=0;j<NN;j++)
		{
			movw.Evaluate(cos(Wn*j*k),-sin(Wn*j*k));
			movwf = movwf + p1.sequence[j] * movw;
		}
		comm -> sequence[k]= movwf.Mod();
	}
	return *(comm);
}
