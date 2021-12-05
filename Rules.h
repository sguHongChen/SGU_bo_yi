#pragma once
#include "config.h"
#include "ChessPoint.h"
#include "NOGO.h"
namespace NOGO {
	//NOGO_Rules
	////////////////////
	//���������ӵĸ��ֶ�����ж� �Լ� �����Ƿ���Ϲ��� ���ж�
	class Rules {
	public:
		//��ȡ������������״̬�µ���
		static int get_qi(const ChessPoint& point);

		//��ȡ������������״̬�µ���
		static int get_eye(const Color color );

		//�жϸ�λ�������Ƿ���Ϲ���
		//if is kill myself or otherself return true 
		static bool is_kill(const ChessPoint& point);


	private:
		
	};//NOGO_Rules
}//namespace NOGO

