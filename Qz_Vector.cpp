/*
     Name:      Krishna rana 
     Course:    CIS 161 ME1
     Date:      10/26/2016
     Program:   Student Quiz record
     Description:  This program keeps records and prints statistical analysis for a class
    			of students. who have three quizzes. The program reads input data from file
				and outputs the student ID, Quizzes score, total average of student,average
				of all the quiz, highest and lowest score for a Quiz to an output file.    				
*/
#include <iostream>//Standard Input/output streams libary
#include <iomanip>//Header providing parametric manipulators
#include <fstream>//Header providing file stream classes
#include <vector>//Header providing vector classes
using namespace std;
//typedef to create an alias name for another data type.
typedef vector<int> ivec;
typedef vector<float> fvec;
//Function prototype
void getdata(ivec&, ivec&, ivec&, ivec&, ifstream&);
void headings(ofstream&);
void findstavg(fvec&, ivec, ivec, ivec, int);
void report(int, ivec&, ivec&, ivec&, ivec&, fvec&, ofstream&);
int findhigh(int, ivec&);
int findlow(int, ivec&);
float findqzavg(int, ivec&);
void hi_lo_avg(int, ivec&, ivec&, ivec&, int, int, int, float, float, float, ofstream&);
void printall(int, ivec&, ivec&, ivec&, ivec&, int, int, int, int, int, int, float,
				float, float, fvec&, ofstream&);
//Main() Function Defination
//This function runs the whole program with step by step intruction written below.
//main() has calls and parameters of other function in the program.
int main()
{
	//Local Definations/ Declarlations
	ivec StudId, Quiz1, Quiz2, Quiz3;
	fvec Studavg;
	int count, hi1, hi2, hi3, lo1, lo2, lo3;
	float qzavg1, qzavg2, qzavg3;
	//This are type associated with fstream,
	//ifstream get file info and ofstrem give info to file.
	ifstream infile("pr2data.txt");
	ofstream outfile;
	//opens the files to write data.
	outfile.open("OUTPUT.txt");
	//file error check, checks if the file exist or not.
	if(!infile)
	//if the file does not exist. prints the message.
		cout<<"file Error: file not present"<<endl;
	else
	{	
		//if file exist, follows this steps
		//function calls
		getdata(StudId, Quiz1, Quiz2, Quiz3, infile);
		//size() method used to find the size of the vector.
		count = StudId.size();
		findstavg(Studavg, Quiz1, Quiz2, Quiz3, count);
		printall(count, StudId, Quiz1, Quiz2, Quiz3, hi1, hi2, hi3, lo1, lo2, lo3, qzavg1,
				qzavg2, qzavg3, Studavg, outfile);	
	}
	
	//close all file after data is updated
	infile.close();
	outfile.close();

	return 0;
}
//getdata() Function Defination
//This function is used to get input from the file.
//The input from file consist of student Id number, three Quiz scores.
//It's return type is null. All vector are passed by reference.
void getdata(ivec& StudId, ivec& Quiz1, ivec& Quiz2, ivec& Quiz3, ifstream& fin)
{
	//Local Definations/ Declarlations
	int id,q1,q2,q3, i;
	//initializing i to 0
	i = 0;
	fin >>id;
	//loop to read data until the trailing value 0 for student ID is encountered.
	while(id != 0)
	{
		//push_back() is used to push the value stored in int id to ivec StudId
		StudId.push_back(id);
		fin >> q1;
		//push_back() is used to push the value stored in int q1 to ivec Quiz1
		Quiz1.push_back(q1);
		fin >> q2;
		//push_back() is used to push the value stored in int q2 to ivec Quiz2
		Quiz2.push_back(q2);
		fin >> q3;
		//push_back() is used to push the value stored in int q3 to ivec Quiz3
		Quiz3.push_back(q3);
		i++;
		fin >> id;
	}
}
//headings() function defination
//This Function is a part of output function, it write the heading and column title to the output file.
//It's return type is void(null)
void headings(ofstream& fout)
{
	//output section, prints to output file
	fout<<setw(50)<<"CIS Department - FALL 2016"<<endl;
	fout<<setw(49)<<"CIS 161 Class Statistics"<<endl;
	fout<<"***********************************************************************"<<endl;
	fout<<"Student"<<setw(15)<<"Quiz 1"<<setw(15)<<"Quiz 2"<<setw(15)<<"Quiz 3"<<setw(15)<<"Average"<<endl;
	fout<<"-----------------------------------------------------------------------"<<endl;
}
//findstavg Function Defination
//This Function is used to calculate average of three quizzes of a student.
//This function gets the data from main(), and main() gets it from getdata().
//It's return type is void(null), All vector are passed by reference.
void findstavg(fvec& Studavg, ivec Quiz1, ivec Quiz2, ivec Quiz3, int count)
{
	
	//Local Definations/ Declarlations
	float avg;
	//counter for the sum of student quiz total 
	float Stavg;
	//loop to add three quiz score for every student Id encounterd.
	for(int i = 0; i < count; i++)
	{
		Stavg = Quiz1[i]+Quiz2[i]+Quiz3[i];
		avg = Stavg / 3;
		Studavg.push_back(avg);
	}
}
//report Function Defination
//This Function is part of output function, it writes the student id, quizzes, and stquiz average.
//This function has findstavg() call to pass value of student id, quizzes, and stquiz average by reference.
//It's return type is void(null), All vector are passed by reference.
void report(int count, ivec& StudId, ivec& Quiz1, ivec& Quiz2, ivec& Quiz3, fvec& Studavg, ofstream& fout)
{
	
	//output section, prints to output file
	//loop to write data of all student read.
	fout<<fixed<<showpoint<<setprecision(2);
	for (int i = 0; i < count; i++)
	{
		fout<<StudId[i]<<setw(15)<<Quiz1[i]<<setw(15)<<Quiz2[i]<<setw(15)<<Quiz3[i]<<setw(18)<<Studavg[i]<<endl;	
	}
}
//findhigh Function Defination
//This is a general purpose function.
//This Function is used to find the highest quiz score of a student in each quiz.
//It's return type is int, it returns the highest quiz score everytime the function is called
int findhigh(int count, ivec& Quiz)
{
	//Local Definations/ Declarlations
	int highest = Quiz[0];
	//loop to find highest score in a quiz	
	for(int i = 0; i < count; i++)
		{
	   		if (highest <= Quiz[i])
				highest = Quiz[i];	
		}
	return highest;
}
//findlow Function Defination
//This is a general purpose function.
//This Function is used to find the lowest quiz score of a student in each quiz.
//It's return type is int, it returns the lowest quiz score everytime the function is called
int findlow(int count, ivec& Quiz)
{
	//Local Definations/ Declarlations
	int lowest = Quiz[0];
	//loop to find lowest score in a quiz	
	for(int i = 0; i < count; i++)
		{
			if (lowest >= Quiz[i])
				lowest = Quiz[i];
		}
	return lowest;
}
//findqzavg Function Defination
//This is a general purpose function.
//This Function is used to find the average of all quiz score of a student in each quiz.
//It's return type is float, it returns the total quiz average for a quiz everytime the function is called
float findqzavg(int count, ivec& Quiz)
{
	//Local Definations/ Declarlations
	float total = 0;
	//loop to find total quiz average
	for(int i = 0; i < count; i++)
	{
		total= total + Quiz[i];
	}
	return total/count;
}
//hi_lo_avg() function defination
//This Function is part of output function, it writes the highest, lowest and quiz average.
//This function has calls to find highest, lowest and quiz average from the input data.
//It's return type is void(null), All vector are passed by reference.
void hi_lo_avg(int count, ivec& Quiz1, ivec& Quiz2, ivec& Quiz3, int hi1, int hi2, int hi3,
				int lo1, int lo2, int lo3, float qzavg1, float qzavg2, float qzavg3, ofstream& fout)
{ 
	//function calls
	//finds highest
	hi1 = findhigh(count, Quiz1);
	hi2 = findhigh(count, Quiz2);
	hi3 = findhigh(count, Quiz3);
	//finds lowest
	lo1 = findlow(count, Quiz1);
	lo2 = findlow(count, Quiz2);
	lo3 = findlow(count, Quiz3);
	//finds Quiz average
	qzavg1 = findqzavg(count, Quiz1);
	qzavg2 = findqzavg(count, Quiz2);
	qzavg3 = findqzavg(count, Quiz3);
	//output section, prints to output file
	fout<<"-----------------------------------------------------------------------"<<endl;
	fout<<"High Score"<<setw(9)<<hi1<<setw(15)<<hi2<<setw(15)<<hi3<<endl<<endl;
	fout<<"Low  Score"<<setw(9)<<lo1<<setw(15)<<lo2<<setw(15)<<lo3<<endl<<endl;
	fout<<"Quiz Average"<<setw(10)<<qzavg1<<setw(13)<<qzavg2<<setw(15)<<qzavg3<<endl;
}
//printall Function Defination
//This Function is the output function, it write's the data in an output file.
//This function has calls of headings(), report() and hi_lo_avg() for output.
//It's return type is void(null)
void printall(int count, ivec& StudId, ivec& Quiz1, ivec& Quiz2, ivec& Quiz3, int hi1,
				int hi2, int hi3, int lo1, int lo2, int lo3, float qzavg1, float qzavg2,
				float qzavg3, fvec& Studavg, ofstream& fout)
{
	headings(fout);
	report(count, StudId, Quiz1, Quiz2, Quiz3, Studavg, fout);
	hi_lo_avg(count, Quiz1, Quiz2, Quiz3, hi1, hi2, hi3, lo1, lo2, lo3, qzavg1, qzavg2, qzavg3, fout);
}
