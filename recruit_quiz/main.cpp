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
	// ���ȃf�[�^�z��
	static const struct
	{
		const char* name;        // ���Ȗ�
		QuestionList(*create)(); // ���쐬�֐��̃A�h���X

	}
	subjectData[] =
	{
{ "���w", CreateMathematicsExam },
{ "����", CreateJapaneseExam },
{ "�p��", CreateEnglishExam },
//{ "����", CreatePhysicsExam },
//{ "�n��", CreateGeographyExam },
//{ "����", CreatePoliticsExam },
//{ "�o��", CreateEconomicsExam },
	};


	vector<Question> questions(3);

	cout << "[���N���[�g�����΍�N�C�Y]\n";

	cout << "���Ȃ�I��ł�������\n";
	for (int i = 0; i < size(subjectData); i++)
	{
		cout << i + 1 << '=' << subjectData[i].name << '\n';
	}

	int subject;
	cin >> subject;

	if (subject > 0 && subject <= size(subjectData))
	{
		questions = subjectData[subject - 1].create();
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