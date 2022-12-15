#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
bool quadrant(int x1, int y1, int x2, int y2)
{
   int q;
   if (x2 > x1 and y2 > y1)
      q = 1;
   else if (x2 < x1 and y2 > y1)
      q = 4;
   else if (x2 < x1 and y2 < y1)
      q = 3;
   else if (x2 > x1 and y2 < y1)
      q = 2;
   cout << q << "    fvxf" << endl;
   if (q == 1 or q == 3)
      return true;
   else
      return false;
}
int main()
{
   fstream newfile;
   newfile.open("map.txt", ios::in);

   string tp;
   int i = 1;
   int slope = 0;
   int x1 = 138, y1 = 51, x2 = 70, y2 = 33, m = 0;
   if (abs(x2 - x1 )<= 2)
   {
      i = 1;
      int x = x1 < x2 ? x1 : x2;
      int xmax = x1 > x2 ? x1 : x2;
      int y = y1 < y2 ? y1 : y2;
      int ymax = y1 > y2 ? y1 : y2;
      while (getline(newfile, tp))
      {
         if (i >= y and i <= ymax)
         {
            if (tp[x] == ' ')
               tp[x] = '*';
         }
         cout << tp << endl;
         i++;
      }
   }
   if (abs(y2 - y1 )<= 2)
   {
      int x = x1 < x2 ? x1 : x2;
      int xmax = x1 > x2 ? x1 : x2;
      int y = y1 < y2 ? y1 : y2;
      i = 1;
      // cout<<"sdfasdf"<<endl;
      int ymax = y1 > y2 ? y1 : y2;
      while (getline(newfile, tp))
      {
         if (i == y)
         {
            for (int j = x; j <= xmax; j++)
            {
               if (tp[j] == ' ')
                  tp[j] = '*';
            }
         }
         cout << tp << endl;
         i++;
      }
   }
   bool flag = quadrant(x1, y1, x2, y2);
   cout << flag << endl;
   if (!flag)
   {
      int temp = y1;
      y1 = y2;
      y2 = temp;

      int x = 1, y = 0;
      if (x1 > x2)
      {
         x = x1;
      }
      else
      {
         x = x2;
      }
      if (x1 < x2)
      {
         int temp = x1;
         x1 = x2;
         x2 = temp;
      }
      if (y1 > y2)
      {
         int temp = y1;
         y1 = y2;
         y2 = temp;
      }
      int d1 = abs(x2 - x1);
      int d2 = abs(y2 - y1);
      // cout<<d1<<d2<<endl;
      if (d1 > d2)
         m = round((double)d1 / d2);
      else
         m = round((double)d2 / d1);
      // cout << m << endl;
      while (getline(newfile, tp))
      {
         if (x >= x2 and y >= y1 and y <= y2)
         {
            x -= m;
            if (tp[x] == ' ')
               tp[x] = '*';
            // cout<<x<<" "<<y<<endl;
         }
         cout << tp << "\n";
         y++;
      }
   }
   else
   {

      int x = 0, y = 0;
      int d1 = abs(x2 - x1);
      int d2 = abs(y2 - y1);
      if (d1 > d2)
         m = round((double)d1 / d2);
      else
         m = round((double)d2 / d1);
      // cout << m << endl;
      int xc = (x1 < x2) ? x1 : x2;
      if (y1 > y2)
      {
         int temp = y1;
         y1 = y2;
         y2 = temp;
      }
      while (getline(newfile, tp))
      {
         if (x <= (abs(x2 - x1)) and y >= y1 and y <= y2)
         {
            x += m;
            if (tp[x + xc] == ' ')
               tp[x + xc] = '*';
            // cout<<x<<" "<<y<<endl;
         }
         cout << tp << "\n";
         y++;
      }
   }
   newfile.close();
}