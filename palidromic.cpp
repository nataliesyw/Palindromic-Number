#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

bool pali (int num)
{
  int remainder, reverse = 0, tempnum;
  tempnum = num;
  while (tempnum > 0)
    {
      remainder = tempnum % 10;
      reverse = reverse * 10 + remainder;
      tempnum = tempnum / 10;
    }
  if (reverse == num)
    {
      return true;
    }
  else
    {
      return false;
    }
}



int main ()
{
  int i, j, k, product;
  int tmp[1000], idx = 0;
  bool duplicate;
  vector < int >myVector;
  string mystring, temp;
  stringstream ss;
  int lower, upper;
  getline(cin, mystring);
  ss << mystring;
  ss >> temp;
  lower = stoi(temp);
  ss >> temp;
  upper = stoi(temp);
  for (i = 100; i <= 999; i++)
    {
      for (j = 100; j <= 999; j++)
	  {
	     product = i * j;
	     if (pali (product) && product >= lower && product <= upper)
	       {
	         //cout << i << " " << j << " " << product << endl;
	         duplicate = false;
	         if (idx > 0)
		      {
		        for (k = 0; k <= idx; k++)
		         {
		           if (tmp[k] == product)
			       {
			         //cout<<"k="<<k<<" "<<tmp[k]<<" "<<product<<endl;
			         duplicate = true;
			         break;
			       }
		        }
		      }

	        if (not duplicate)
		     {
		       //cout <<"myVector.push_back "<<product<<endl;
		       myVector.push_back (product);
		       tmp[idx]=product;
		       //cout << "idx=" << idx << " tmp=" << tmp[idx] << endl;
		       idx++;
	  	     }
          }
	   }
    }


  // sort vector
  sort (myVector.begin (), myVector.end ());

  // print vector
  for (int & i : myVector)
   {
     cout << i << endl;
   }

  return 0;
}
