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

		//if is kill myself or otherself return true 
		static bool is_kill(const ChessPoint& point);
		

		//eye
		
		//��ȡ������������״̬�µ���
		static int get_eye(const Color color);

		//�жϸ������Ƿ����Լ��Ļ��� 
		//@return �����ܹ������۵ĸ���
		static int is_jaws(const ChessPoint& point);

		//�жϸ������ܷ��Ƶ��Է�����
		static bool is_Broken_eyes(const ChessPoint& point);
		

		//eligible
		
		//���ص�ǰ��� ��һ����ɫ�� ���п����ӵ�
		static std::vector<ChessPoint&> eligible(const Color color);

		//�����Ƿ��ǹ����Ŀ����ӵ�
		static bool is_all_eligible(const ChessPoint& point);

		//���ص�ǰ��� ��һ����ɫ�� ���п����ӵ� �ж��ֲ������ӵĵ�
		static std::vector<ChessPoint&> just_my_eligible(const Color color);


	private:
		//��ȡ�������ӵ���
		static int get_this_qi(const ChessPoint& point);

		//if is kill myself return true 
		static bool is_kill_myself(const ChessPoint& point);

		//if is kill otherself return true 
		static bool is_kill_otherself(const ChessPoint& point);

		//�жϵ�������λ���Ƿ������ӵ���
		static bool isEyes(ChessPoint point);


	};//NOGO_Rules
}//namespace NOGO

