#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;

// A new student
struct Student
{
    char name[30];
    int birthDay, birthMonth, birthYear, chemGrade, itGrade, physicsGrade;

    string getStudType()
    {
        if(itGrade == 5 && chemGrade == 5 && physicsGrade == 5)
            return "excellent";
        if((physicsGrade == 5 || physicsGrade == 4) && (chemGrade == 5 || chemGrade == 4) && (itGrade == 5 || itGrade == 4))
            return "good";
        if(itGrade == 3 && chemGrade == 3 && physicsGrade == 3)
            return "bad";
    }

    float getAvrg()
    {
        return (chemGrade+itGrade+physicsGrade)/3.;
    }

    void printStudLine()
    {
        printf("\n%s\n","---------------------+------------+------------+------------+---------------+--------------");
        printf("%-20s | %02d/%02d/%-4d | %-10d | %-10d | %-13d | %f",name,birthDay,birthMonth,birthYear,chemGrade,itGrade,physicsGrade,getAvrg());
    }

};

void studTableHeader(char title[20])
{
    printf("\n%s",title);
    printf("\n\n%-20s | %-10s | %-10s | %-10s | %-13s | %s","Name","Birth date","Chemistry grade","IT grade","Physics grade","Average grade");
};

// Function to print out an array of students
void printStudentList(Student *studList,int studListLenght,char title[20])
{
    studTableHeader(title);

    for (int i = 0; i < studListLenght; i++)
    {
        studList[i].printStudLine();
    }
    printf("\n");
};

int randint(int minnum, int maxnum)
{
    int rnum = (rand() % maxnum + minnum);
    if (rnum > maxnum)
        return maxnum;
    else
        return rnum;
};

int main()
{
    string tempStr;
    int percentK;
    int tempItr = 0;
    int studnum;

    printf("%s","How many students?: ");
    scanf("%d",&studnum);

    Student studArr[studnum];
    Student avrgSorted[studnum];

    for (int i = 0; i < studnum; i++)
    {
        char newname[30];
        int newbirthDay, newbirthMonth, newbirthYear, newchemGrade, newitGrade, newphysicsGrade;
        /*
        printf("%s %d %s","\nStudent number ",i,"\n");

        printf("%s","Name: ");
        scanf("%s",newname);

        printf("%s","Birth day: ");
        scanf("%d",&newbirthDay);

        printf("%s","Birth month: ");
        scanf("%d",&newbirthMonth);

        printf("%s","Birth year: ");
        scanf("%d",&newbirthYear);

        printf("%s","Chemistry grade: ");
        scanf("%d",&newchemGrade);

        printf("%s","IT grade: ");
        scanf("%d",&newitGrade);

        printf("%s","Physics grade: ");
        scanf("%d",&newphysicsGrade);

        studArr[i] = Student{"", newbirthDay, newbirthMonth, newbirthYear, newchemGrade, newitGrade, newphysicsGrade};

        for (int j = 0; j < sizeof(newname); j++) // TO DO: set name properly
        {
            studArr[i].name[j] = newname[j];
        }
        */
        studArr[i] = Student{"Frank Reynolds", randint(1,30), randint(1,12), 2003, randint(3,5), randint(2,5), randint(3,5)};
        system("cls");
    }

    for (int i = 0; i < studnum; i++)
    {
        avrgSorted[i] = studArr[i];
    }

    float groupAvrg=0;

    for (int i = 0; i < studnum; i++)
    {
        groupAvrg+=studArr[i].getAvrg();
    }
    groupAvrg/=studnum;

    while(true)
    {
        int numchoice;

        printf("\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s","1) All students","2) Excellent students",
               "3) Bad students","4) Good students","5) Excellent at physics", "6) Sort students by their grade averages",
               "7) Students above group's grade average", "8) Students below group's grade average",
               "9) Students with a grade average difference not more than %d percent of the group's average",
               "10) Good at chemistry or physics");

        printf("%s","\nChoose an option: ");
        scanf("%d",&numchoice);

        switch(numchoice)
        {
        case 1:
            printStudentList(studArr, studnum, "All students:");
            break;

        case 2:
            studTableHeader("Excellent students:");
            for (int i = 0; i < studnum; i++)
            {
                if (studArr[i].getStudType() == "excellent")
                    studArr[i].printStudLine();
            }
            printf("\n");
            break;

        case 3:
            studTableHeader("Bad students:");
            for (int i = 0; i < studnum; i++)
            {
                if (studArr[i].getStudType() == "bad")
                    studArr[i].printStudLine();
            }
            printf("\n");
            break;

        case 4:
            studTableHeader("Good students:");
            for (int i = 0; i < studnum; i++)
            {
                if (studArr[i].getStudType() == "good")
                    studArr[i].printStudLine();
            }
            printf("\n");
            break;

        case 5:
            studTableHeader("Excellent at physics:");
            for (int i = 0; i < studnum; i++)
            {
                if (studArr[i].physicsGrade == 5)
                    studArr[i].printStudLine();
            }
            printf("\n");
            break;

        case 6: // Doesn't work for some reason!
            int minStud;
            Student temp;
            for (int i = 0; i < studnum - 1; i++)
            {
                minStud = i;

                for (int j = i + 1; j < studnum; j++)
                {
                    if(avrgSorted[j].getAvrg() > avrgSorted[minStud].getAvrg())
                    {
                        minStud = j;
                        printf("New J: %d",j);
                    }
                }
                temp = avrgSorted[i];
                avrgSorted[i] = avrgSorted[minStud];
                avrgSorted[minStud] = temp;
            }
            printStudentList(avrgSorted,studnum,"Sorted by average:");
            break;

        case 7:
            printf("\nThe group average: %f\n",groupAvrg);
            studTableHeader("Above average students:");
            for (int i = 0; i < studnum; i++)
            {
                if (studArr[i].getAvrg() > groupAvrg)
                    studArr[i].printStudLine();
            }
            printf("\n");
            break;

        case 8:
            printf("\nThe group average: %f\n",groupAvrg);
            studTableHeader("Below average students:");
            for (int i = 0; i < studnum; i++)
            {
                if (studArr[i].getAvrg() < groupAvrg)
                    studArr[i].printStudLine();
            }
            printf("\n");
            break;

        case 9:
            printf("\nThe group average: %f\n", groupAvrg);
            printf("Enter percentage (K): ");
            scanf("%d",&percentK);
            printf("\nStudents with a grade average difference not more than %d percent of the group's average:", percentK);
            studTableHeader("");

            for (int i = 0; i < studnum; i++)
            {
                float percentRange = (groupAvrg * percentK) / 100;
                if (studArr[i].getAvrg() > groupAvrg)
                {
                    if (studArr[i].getAvrg() - groupAvrg <= percentRange)
                        studArr[i].printStudLine();
                } else {
                    if (groupAvrg - studArr[i].getAvrg() <= percentRange)
                        studArr[i].printStudLine();
                }
            }
            printf("\n");
            break;

            case 10:
            studTableHeader("Good at chemistry or physics:");
            for (int i = 0; i < studnum; i++)
            {
                if((studArr[i].physicsGrade == 5 || studArr[i].physicsGrade == 4) && (studArr[i].chemGrade == 5 || studArr[i].chemGrade == 4))
                    studArr[i].printStudLine();
            }
            printf("\n");
            break;

        }

        printf("%s","\nEnter \"b\" to go back: ");
        scanf("%s",tempStr);
        system("cls");
    }

}
