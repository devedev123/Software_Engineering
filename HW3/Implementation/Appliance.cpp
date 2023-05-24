#include "RequirementSystem.h"

/*
Function : Appliance
Description : Appliance class constructer
Return type :
Parameters  :
*/
Appliance::Appliance()
{
	ApplianceUi applianceUi;
	applianceUi.selectAppliance(this);
}


/*
Function : newApply
Description : call addApply
Return type : Apply*
Parameters : CommonMember*, MemberList*, string 
*/
Apply* Appliance::newApply(CommonMember* currentLoginMember, MemberList* memberList, string companyNum)
{
	Member** members = memberList->getMembers();
	int numOfMembers = memberList->getMemberNum();
	for (int i = 0; i < numOfMembers; i++)
	{
		if (members[i]->getIsCompany())	//if member is company
		{
			Company* company = (Company*)members[i];
			if (company->getCompanyNumber() == companyNum)	//�ش� member�� ������ company���
			{
				string companyName = company->getCompanyName();
				
				Employment * employment = (company->getEmploymentList()->listEmployments())[0]; //classroom Q&A-> �ϳ��� ä�������� ����
				string work = employment->getWork();
				string deadline = employment->getDeadline();
				int num = employment->getNumOfPeople();

				employment->plusApplyNum();	//company ��� ���� �ش� employment�� �����ڼ� ����
				ApplyList* applyList = currentLoginMember->getApplyList();	//�������� applylist �޾ƿ�
				Apply* apply = applyList->addApply(companyName, companyNum, work, num, deadline);
				return apply;
			}
		}
	}
}