#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
    char sent[200];
    char sent2[200];
    char sent3[200];
    char sent4[200];
    int length = 0;
    int length2 = 0;
    int length3 = 0;
    int indy = 0;
    int count = 0;
    char hold;

    cout << "enter 1: ";
    cin.get(sent, 200, '\n');
    cin.ignore(100, '\n');

    cout << "enter 2: ";
    cin.get(sent2, 200, '\n');
    cin.ignore(100, '\n');

    cout << "enter 3: ";
    cin.get(sent3, 200, '\n');
    cin.ignore(100, '\n');
    
    length = strlen(sent3);
    length2 = strlen(sent2);
    length3 = strlen(sent);
    for (int i = 0; i < 200; ++i)
    {
        if (sent3[i] != sent2[i])
	{
	    sent4[i] = sent3[i];
	}
	else if (sent3[i] == sent2[i])
	{
           indy = i;
	   for (indy; indy < length2; ++indy)
           {
	     if (sent3[indy] == sent2[indy])
	              count += 1;
	   }
	   if (count == length2)
           {
             for (int j = 0; j < length3; ++j, ++indy)
	     {
	       hold = sent[j];
	       sent[j] = sent4[indy];
	       sent4[indy] = hold;
	     }
	   }
	   else
             sent4[i] = sent3[i];
	}
    }
    sent4[length] = '\0';

    cout << sent << endl;
    cout << sent2 << endl;
    cout << sent3 << endl;
    cout << sent4 << endl;
	       

    
    return 0;
}
