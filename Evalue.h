#pragma once
#include "NOGO.h"
#include "ChessPoint.h"
namespace NOGO {
	class Evalue
	{
	public:
		//��̬��������
		static int evalue(const ChessPoint& point);
	private:
		//���ؼ��������ӵĸ�����ȥ�Է������ӵĸ���
		int more_eligible(const Color color);

		//���ضԷ��������ӵĸ���
		int more_eligible(const Color color);

		//���ؼ������������Է�������
		int more_eligible(const Color color);

		//TODO  ���Լ��������ӶԷ��������ӵ�λ�ü����
		//�����¶Է����Ӻ����λ���п��ܱ�ɶԷ��������Լ�Ҳ�����µ�λ��


	};
}
