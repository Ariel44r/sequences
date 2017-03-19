//the complex library made by ARIEL DIAZ

#include<iostream>
#include<math.h>

using namespace std;

class complex
{
	public:
	double Re,Im;

	public:
		complex (const double Re,const double Im)
		{
			this->Re = Re;
			this->Im = Im;
		}

		double Mod ()
		{
			return (sqrt(pow(Re,2)+pow(Im,2)));
		}

		double Phase ()
		{
			if ((Re==0)&&(Im==0))
			{
				return (0);
			}
			else
				if (((Re>=0)&&(Im>=0))||((Re>=0)&&(Im<=0)))
				{
					return (180*atan(Im/Re)/3.141592654);
				}
				else
					if ((Re<0)&&(Im>=0))
					{
						return (180 + 180*atan(Im/Re)/3.141592654);
					}
					else
						if((Re<0)&&(Im<0))
						{
							return (180 + 180*atan(Im/Re)/3.141592654);
						}
		}

		double Real (complex a)
		{
			return (Re);
		}

		double Imag (complex b)
		{
			return (Im);
		}

		void Evaluate(double aaa,double bbb)
		{
			Re = aaa;
			Im = bbb;
		}

		void Print()
		{
			if (Im>=0)
			{
				if (Im==0)
				{
					cout<<"Z =\t"<<Re<<endl;
				}
				else
				{
					cout<<"Z =\t"<<Re<<"\t+\tj"<<Im<<endl;
				}
			}
			else
			{
				cout<<"Z =\t"<<Re<<"\t-\tj"<<-Im<<endl;
			}
			cout<<"abs (Z) =\t"<<Mod ()<<"\nphase (Z) =\t"<<Phase()<<"\n";
			cout<<endl;
		}

		~complex (){}

};

//Operator_Overload
complex& operator +(const complex &p1,const complex &p2)
{
	return *(new complex(p1.Re + p2.Re, p1.Im + p2.Im) ); 
}

//Operator_Overload
complex& operator -(const complex &p1,const complex &p2)
{
	return *(new complex(p1.Re - p2.Re, p1.Im - p2.Im) ); 
}

//Operator_Overload
complex& operator *(const complex &p1,const complex &p2)
{
	return *(new complex(p1.Re*p2.Re - p1.Im*p2.Im,p1.Re*p2.Im + p2.Re*p1.Im) ); 
}

//Operator_Overload
complex& operator *(const double &p1,const complex &p2)
{
	return *(new complex(p1*p2.Re,p1*p2.Im) ); 
}

//Operator_Overload
complex& operator /(const complex &p1,const complex &p2)
{
	return *(new complex(((p1.Re*p2.Re+p1.Im*p2.Im)/(pow(p2.Re,2)+pow(p2.Im,2))),((p1.Im*p2.Re-p1.Re*p2.Im)/(pow(p2.Re,2)+pow(p2.Im,2)))) ); 
}
