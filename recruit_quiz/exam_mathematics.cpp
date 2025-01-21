#include "exam_mathematics.h"
 #include "utility.h"
 #include <random>
 using namespace std;

 //�ő���񐔂����߂�
 int gcd(int a, int b)
 {
	 //�]�肪0�ɂȂ������̏�����Ԃ�
	 while (b)
	 {
		 int r = a % b;
		 a = b;//���������̔폜���ɂ���
		 b = r;//�]������̏����ɂ���
	 }
	 return a;
 }

//���w�̖����쐬����
 QuestionList CreateMathematicsExam()
 {
	 QuestionList questions(3);

	 random_device rd;
	 mt19937 rand(rd());

	 //�|���Z
	 int x = uniform_int_distribution<>(1, 30)(rand);
	 int y = uniform_int_distribution<>(1, 20)(rand);
	 questions[0].q = to_string(x) + "x" + to_string(y) + "�̓����́H";
	 questions[0].a = to_string(x * y);

	 //����Z
	 x = uniform_int_distribution<>(1, 30)(rand);
	 y = uniform_int_distribution<>(1, 20)(rand);
	 questions[1].q = to_string(x * y) + "��" + to_string(y) + "�̓����́H";
	 questions[1].a = to_string(x);

	 //���G�Ȏ�
	 x = uniform_int_distribution<>(1, 100)(rand);
	 y = uniform_int_distribution<>(1, 10)(rand);
	 int z = uniform_int_distribution<>(1, 10)(rand);
	 int w = uniform_int_distribution<>(1, 20)(rand);
	 questions[2].q = to_string(x) + "-(" + to_string(y * w) + "+" + to_string(z * w) + ")��" + to_string(w) + "�̓����́H";
	 questions[2].a = to_string(x - (y + z));

	 //�O�p�`�̖ʐ�
	 x = uniform_int_distribution<>(1, 10)(rand);
	 y = uniform_int_distribution<>(1, 5)(rand) * 2;
	 questions.push_back({ "�ʐ�" + to_string(x * y / 2) + "cm^2�A���" + to_string(y) + "cm�̎O�p�`�̍��������߂�B",to_string(x) });

	 //�~���̑̐�
	 x = uniform_int_distribution<>(1, 10)(rand);
	 y = uniform_int_distribution<>(1, 5)(rand) * 3;
	 questions.push_back
	 ({
		 "��ʂ̔��a" + to_string(x) + "cm�A����" + to_string(y) + "cm�̉~��������B\n" +
		 "���̉~���̑̐ς�X��cm^3�Ƃ���BX�̒l�����߂�B",
		 to_string(x * x * y / 3)
		 });

	 //�T�C�R���̊m��
	 x = uniform_int_distribution<>(1, 5)(rand);
	 y = uniform_int_distribution<>(1, 6 - x)(rand);
	 z = gcd(y + 1, 6);
	 questions.push_back
	 ({
		 "�T�C�R�����P�ӂ��āA" + to_string(x) + "����" + to_string(x + y) +
		 "���ł�m�������߂�B",
		 to_string((y + 1) / z) + "/" + to_string(6 / z)
		 });

	 //����
	 x = uniform_int_distribution<>(3, 7)(rand);
	 y = uniform_int_distribution<>(1, x)(rand);
	 z = 1;
	 for (int i = 0; i < y; i++)
	 {
		 z *= x - i;
	 }
	 questions.push_back({ to_string(x) + "�l�̂���" + to_string(y) + "�l��I��ŕ��ׂ���@�͉��ʂ肠�邩�H",to_string(z) });

	 //�g�ݍ��킹
	 x = uniform_int_distribution<>(3, 6)(rand);
	 y = uniform_int_distribution<>(1, x)(rand);
	 z = 1;
	 for (int i = 0; i < y; i++)
	 {
		 z *= x - i;
	 }
	 for (int i = 0; i < y; i++)
	 {
		 z /= y - i;
	 }
	 questions.push_back({ to_string(x) + "�l�̂���" + to_string(y) + "�l��I�ԑg�ݍ��킹�͉��ʂ肠�邩�H",to_string(z) });

	 return questions;
 }