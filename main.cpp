// Git Repo: https://github.com/jim3692/challenge-who-has-to-pay

#include <iostream>
#include <cstdlib>

using namespace std;

const int StudentCount = 20;

const char chars[] = "ABCDEFGHIJKLMNOPQRST";

class Student
{
    public:
        int LentTo = -1;
        int Index = -1;
        Student(int i, int l) : Index(i), LentTo(l) { }
};

int main()
{
    Student *Classroom[StudentCount];

    // Define who lent to whom
    for (int i = 0; i < StudentCount; i++)
    {
        int l =  ((rand() % 3) != 0 ? (rand() % StudentCount) : -1);
        Classroom[i] = new Student(i,l);
        
        cout << chars[i] << "->";
        if (l == -1) { cout << "'None'"; }
        else { cout << chars[l]; }
        cout << endl;
    }

    cout << endl << "Calculating results..." << endl;

    // Calculate who owes to whom
    for (int i = 0; i < StudentCount; i++)
    {
        if (Classroom[i]->LentTo == -1) continue;

        int c = i;
        int l = Classroom[i]->LentTo;

        while (true)
        {
            if (l == -1) break;
            if (l == c) { Classroom[l]->LentTo = -1; break; }

            c = l;
            l = Classroom[l]->LentTo;
        }

        Classroom[i]->LentTo = c;
    }
    
    cout << endl << "The results are..." << endl << endl;

    // Announce results
    for (int i = 0; i < StudentCount; i++)
    {
        Student *current = Classroom[i];
        if ((*current).LentTo == -1) continue;
        
        int _owesTo = (*current).LentTo;
        int _lentTo = (*current).Index;

        cout << chars[_owesTo] << " owes to " << chars[_lentTo] << endl;
    }

    return 0;
}
