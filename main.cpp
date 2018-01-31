// Git Repo: https://github.com/jim3692/challenge-who-has-to-pay

#include <iostream>
#include <cstdlib>

using namespace std;

const int StudentCount = 20;

const char chars[] = "ABCDEFGHIJKLMNOPQRST";

class Student
{
    public:
        Student *LentTo;
        int Index;
        Student(int i) : Index(i) { }
};

int main()
{
    Student *Classroom[StudentCount];

    // Initialize Students and define who lent to whom
    for (int i = 0; i < StudentCount; i++)               
    {
        Classroom[i] = new Student(i);
        int lend = (rand() % StudentCount);
        (*Classroom[i]).LentTo = Classroom[lend];
        
        cout << chars[i] << "->";
        if (i == lend) { cout << "'None'"; }
        else { cout << chars[lend]; }
        cout << endl;
    }

    cout << endl << "Calculating results..." << endl;

    // Calculate who owes to whom
    for (int i = 0; i < StudentCount; i++)
    {
        Student *current = Classroom[i];

        while (true)
        {
            if (current == nullptr) break;;
            if ((*current).LentTo == nullptr) break;
            if ((*current).LentTo == current) { (*current).LentTo = nullptr; break; }

            current = (*current).LentTo;
        }

        (*Classroom[i]).LentTo = current;
    }
    
    cout << endl << "The results are..." << endl << endl;

    // Announce results
    for (int i = 0; i < StudentCount; i++)
    {
        Student *current = Classroom[i];
        if ((*current).LentTo == nullptr) continue;
        
        int _owesTo = (*(*current).LentTo).Index;
        int _lentTo = (*current).Index;

        cout << chars[_owesTo] << " owes to " << chars[_lentTo] << endl;
    }

    return 0;
}
