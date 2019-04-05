#include <iostream>
#include <cstring>
#include <cstdlib>
#include <windows.h>
using namespace std;
class Course{
	public:
		int  CourseId;
		string courseName;
		int credit;
		Course(int CourseId1, string courseName1, int credit1)
		{
			CourseId=CourseId1;
			courseName=courseName1;
			credit=credit1;
			cout<<"you have set a course:"<<endl;
			cout<<"ID: "<<CourseId<<"\t"<<"name: "<<courseName<<"\t"<<"credit: "<<credit<<endl; 
		}
		Course()
		{
			;
		}
};
class Person{
	public:
		string name;
		int age;
		Person(string name1, int age1)
		{
		age=age1;
		name=name1;
		}
		Person()
		{
			;
			}	
};
class Teacher: public Person{
	public:
	int teacherId;
	int *TeachCourse;
	int courseNum;
	Teacher(string name1, int age1, int teacherId1, int n):Person(name1,age1)
	{
	courseNum=0;
	teacherId=teacherId1;
	TeachCourse = new int[n];
	}
	Teacher()
	{
		;
	}
	void teach()
	{cout <<"i am a teacher, i teach my student"<<endl;}
	void setCourseId(Course course)
	{
		TeachCourse[courseNum++]=course.CourseId;
	}
};
class Student:public Person{
	public:
		int courseCount;
		int number;
		int myCourses[100];
		int n;
		Student(string name1, int age1, int number1, int n1):Person(name1,age1)
		{
			courseCount=0;
			number=number1;
			n=n1;
			cout<<"welcome "<<name<<"\t your age is: "<<age<<"\t your number is "<<number<<endl;
		}
		Student() 
		{
			;
		}
		void selectCourse( Course course)
		{
			for(int cnt=0;cnt<courseCount;cnt++)
			{
				if(myCourses[cnt]==course.CourseId)
				{
					cout<<"you have selected that!"<<endl;
					return;
				}
			}
			myCourses[courseCount++]=course.CourseId; 
			cout<<name<<" you succeed selecting : "<<endl;
			cout<<"ID: "<<course.CourseId<<"\t"<<"name: "<<course.courseName<<"\t"<<"credit: "<<course.credit<<endl; 
		}
		void deleteCourse(Course course)
		{
			int temp=-1;
			 for(int cnt=0;cnt<courseCount;cnt++)
			 {
			 	if(myCourses[cnt]==course.CourseId)
			 	{
			 		temp=cnt;
			 		cout<<name<<"  you delected :"<<endl;
			 		cout<<"ID: "<<course.CourseId<<"\t"<<"name: "<<course.courseName<<"\t"<<"credit: "<<course.credit<<endl; 
			 		break;
				}
			 }
			 if(temp==-1)
			 {
			 	cout<<"you haven't select that!"<<endl;
			 	return;
			 }
			 myCourses[temp]=0;
			 myCourses[temp]=myCourses[courseCount-1];
			 courseCount--;
		}
		void showCourse()
		{
			cout<<"CourseCount is "<<courseCount<<endl;
			cout<<"CourseSelect is ";
			for(int cnt=0;cnt<courseCount;cnt++)
			{
				cout<<myCourses[cnt]<<"\t";
			}
			cout<<endl;
		}
		bool judge()
		{
			if(courseCount>5) return true;
			return false;
		}
		void judgeResult()
		{
			if(judge()==1)
			{
				cout<<"enough!"<<endl;
			}
			else
			{
				cout<<"not enough!"<<endl;
			}
		}
};
class TeachingAssistant:public Student{
	public:
		int assCourses[100];
		int assCourseCount;
		TeachingAssistant(string name1, int age1, int number1, int n1):Student(name1,age1,number1,n1)
		{
			assCourseCount=0;
		}
		TeachingAssistant(){
			;
		}
		void teach()
		{cout <<"i am a teaching assistant, i help my teacher teach his students"<<endl;}
		void selectCourse(Teacher t)
		{
			for(int cnt=0;cnt<assCourseCount;cnt++)
			{
				if(assCourses[cnt]==t.teacherId)
				{
					cout<<"you have selected this teacher!"<<endl;
					return;
				}
			}
			assCourses[assCourseCount++]=t.teacherId;
			cout<<"assistant "<<name<<" succeed selecting teacher:"<<endl;
			cout<<"ID:"<<t.teacherId<<" name:"<<t.name<<endl;
		}
		void deleteCourse(Teacher t)
		{
			int temp=-1;
			for(int cnt=0;cnt<assCourseCount;cnt++)
			{
				if(assCourses[cnt]==t.teacherId)
				{
					temp=cnt;
					cout<<"assistant "<<name<<" succeed delecting teacher:"<<endl;
					cout<<"ID:"<<t.teacherId<<" name:"<<t.name<<endl;
					break;
				}
			}
			if(temp==-1)
			{
				cout<<"you haven't select that teacher!"<<endl;
				return;
			}
			assCourses[temp]=assCourses[assCourseCount-1];
			assCourseCount--;
		}
		void showassistant()
		{
			cout<<"the CourseNum I assistant is "<<assCourseCount<<endl;
			cout<<"Teacher I Select is ";
			for(int cnt=0;cnt<assCourseCount;cnt++)
			{
				cout<<assCourses[cnt]<<"\t";
			}
			cout<<endl;
		}
		
};
Student student[100];
int stu_pointer=0;
Teacher teacher[100];
int tea_pointer=0;
TeachingAssistant assistant[100];
int ass_pointer=0; 
Course weijifen(1,"weijifen",6);
Course xiandai(2,"xiandai",4);
Course junli(3,"junli",1);
void student_in(int stu_id){
LABEL_stu_in_00:
	int flag=0;
	cout<<"1.Selece course\t2.Delect course\t3.My course\t4.judge\t5.Exit"<<endl;
	cin>>flag;
	switch(flag){
		case 1:{
			LABEL_stu_in_01:
			cout<<"you can choose from above\n"<<"1.weijifen\t2.xiandai\t3.junli\t4.Exit"<<endl;
				int flag=0;
				cin>>flag;
				switch(flag){
					case 1:{
						student[stu_id].selectCourse(weijifen); 
						Sleep(500);
						system("cls");
						goto LABEL_stu_in_01;
						break;
					}
					case 2:{
						student[stu_id].selectCourse(xiandai);
						Sleep(500);
						system("cls");
						goto LABEL_stu_in_01;
						break;
					}
					case 3:{
						student[stu_id].selectCourse(junli);
						Sleep(500);
						system("cls");
						goto LABEL_stu_in_01;
						break;
					}
					case 4:{
						system("cls");
						goto LABEL_stu_in_00;
						break;
					}
					case 5:{
						return ;
						break;
					}
					default :{
						cout<<"wrong input!"<<endl;
						system("cls");
						goto LABEL_stu_in_01;
						break;
					}
				}
					
			break;
		}
		case 2:{
			LABEL_stu_in_02:
			cout<<"you can choose which to delect from above\n"<<"1.weijifen\t2.xiandai\t3.junli\t4.Exit"<<endl;
				int flag=0;
				cin>>flag;
				switch(flag){
					case 1:{
						student[stu_id].deleteCourse(weijifen); 
						Sleep(500);
						system("cls");
						goto LABEL_stu_in_02;
						break;
					}
					case 2:{
						student[stu_id].deleteCourse(xiandai);
						Sleep(500);
						system("cls");
						goto LABEL_stu_in_02;
						break;
					}
					case 3:{
						student[stu_id].deleteCourse(junli);
						Sleep(500);
						system("cls");
						goto LABEL_stu_in_02;
						break;
					}
					case 4:{
						system("cls");
						goto LABEL_stu_in_00;
						break;
					}
					default :{
						cout<<"wrong input!"<<endl;
						Sleep(500);
						system("cls");
						goto LABEL_stu_in_01;
						break;
					}
				}
					
			break;
		}
		case 3:{
			student[stu_id].showCourse();
			goto LABEL_stu_in_01;
			break;
		}
		case 4:{
			student[stu_id].judgeResult();
			break;
		}
		case 5:{
			break;
		}
		default:{
			cout<<"wrong input!"<<endl;
			goto LABEL_stu_in_00;
			break;
		}
		}
	}
void menu(){
	cout<<"************************\n"<<"* Course select system *\n"<<"************************"<<endl;
	cout<<"1.Student\t2.Teacher\t3.Assistant\t4.Exit"<<endl;
	cout<<"-->";
}
void student_out(){
LABEL_stu:
	cout<<"1.New student\t2.Sign in\t3.Exit\n-->"<<endl;
	int flag=0;
	int stu_id=0;
	cin>>flag;
	switch(flag)
	{
		case 1:
			{
			cout<<"input your information,as follow:\nname age number n"<<endl;
			string name;
			int age;
			int number;
			int n;
			cin>>name>>age>>number>>n;
			student[stu_pointer].name=name;
			student[stu_pointer].age=age;
			student[stu_pointer].number=number;
			student[stu_pointer].n=n;
			cout<<"register succeed!\n"<<"your id is "<<stu_pointer<<"\nback to last menu to continue!"<<endl;
			Sleep(500);
			stu_pointer++;
			system("cls");
			goto LABEL_stu; 
			break;
			}
		case 2:
			{
				cout<<"input your name:"<<endl;
				int panduan=0;
				string name;
				cin>>name;
				for(int cnt=0;cnt<stu_pointer;cnt++)
				{
					if(name==student[cnt].name)
					{
						stu_id=cnt;
						system("cls");
						cout<<"welcome "<<name<<"!"<<endl;
						panduan=1;
						student_in(stu_id);
						goto LABEL_stu;
						break;
					}
				}
				if(panduan==0)
				{
					cout<<"your haven't registed!"<<endl;
					Sleep(500);
					system("cls");
					goto LABEL_stu;
				}
			}
		default : break;
		
	}
} 
void Teacher_out(){
	cout<<"please wait for next version!"<<endl; 
	Sleep(500);
	system("cls");
}
void Assistant_out(){
	cout<<"please wait for next version!"<<endl; 
	Sleep(500);
	system("cls");
}
int main()
{
LABEL_main0:
	menu();
	int flag=0;
	cin.sync();
	scanf("%d",&flag);
	switch(flag){
		case 1: system("cls");student_out();goto LABEL_main0;break;
		case 2: Teacher_out();goto LABEL_main0;break;
		case 3: Assistant_out();goto LABEL_main0;break;
		case 4:return 0;break;
		default: cout<<"input error!"<<endl;fflush(stdin);goto LABEL_main0;break;
	}
	return 0;
 }  
