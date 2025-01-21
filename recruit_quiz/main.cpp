#include "question.h"
#include "exam_mathematics.h"
#include "exam_japanese.h"
#include "exam_english.h"
#include "exam_geography.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;



int main()
{
	vector<Question> questions(3);

	cout << "[���N���[�g�����΍�N�C�Y]\n";

	cout << "���Ȃ�I��ł�������\n1=���w\n2=����\n3=�p��\n4=����\n5=�n��\n";
	int subject;
	cin >> subject;
	if (subject == 1) 
	{
		questions = CreateMathematicsExam();
	}
	else if (subject == 2) 
	{
		questions = CreateMathematicsExam();
	}
	else if (subject == 3)
	{
		questions = CreateEnglishWordExam();
		QuestionList phraseExam = CreateEnglishPhraseExam();
		questions.insert(questions.end(), phraseExam.begin(), phraseExam.end());
	}
	else if (subject == 5)
	{
		questions = CreatePrefecturesExam();
	}
	

	for (const auto& e : questions)
	{
		cout << e.q << "\n";

		string answer;
		cin >> answer;

		if (answer == e.a)
		{
			cout << "����!\n";
		}
		else
		{
			cout << "�ԈႢ!������" << e.a << "\n";
		}
	}//for questions
}