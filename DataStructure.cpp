/**/
#include <iostream>
#include <fstream>
constexpr int MAXSIZE = 20;
using namespace std;
typedef struct perInfo {
public:
    string sName;
    string major;
    string phoNum;
    string gender;
};
void printperInfo(perInfo* info)
{
    cout << info->sName << "\t" << info->gender << "'\t" << info->gender << "\t" << info->phoNum << endl;
}
typedef struct actInfo {
public:
    string actName;
    string actDate;
    double actScore;
    actInfo* next=NULL;
};
void printactInfo(actInfo* info)
{
    actInfo *temp;
    temp = info;
    if (temp == nullptr)
    {
        cout << "无活动信息" << endl;
    }
    else
        while (temp!= NULL)
        {
            cout << temp->actName << "\t" << temp->actDate << "\t" << temp->actScore << endl;
            temp = temp->next;
        }
}
void addactInfo(actInfo* info)
{
    if (info != NULL) 
    {
        while (info->next != NULL)
        {
            info = info->next;
        }
        actInfo* temp = nullptr;
        string actName, actDate;
        double actScore;
        cout << "输入活动名 活动日期 活动综测分" << endl;
        cin >> actName >> actDate >> actScore;
        temp->actDate = actDate;
        temp->actName = actName;
        temp->actScore = actScore;
        info->next = temp;
        info = info->next;
        info->next = NULL;
    }
    else
    {
        actInfo* temp = nullptr;
        string actName, actDate;
        double actScore;
        cout << "输入活动名 活动日期 活动综测分" << endl;
        cin >> actName >> actDate >> actScore;
        temp->actDate = actDate;
        temp->actName = actName;
        temp->actScore = actScore;
        info = temp;
        info->next = NULL;
    }
}
void changeactInfo(actInfo* info)
{
    string actName;
    bool flag=false;
    printactInfo(info);
    cout << "输入修改活动名称" << endl;
    cin >> actName;
    while (info->next != NULL)
    {
        if (info->actName == actName)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        cout << "输入修改后的活动名称 活动日期 活动分数" << endl;
        string actName, actDate;
        double actScore=0;
        info->actName = actName;
        info->actDate = actDate;
        info->actScore = actScore;
    }
    else
    {
        cout << "未找到名称为" << actName << "的活动" << endl;
    }
}
actInfo* deleteactInfo(actInfo* info)
{
    string actName;
    actInfo* head = info;
    bool flag = false;
    printactInfo(info);
    cout << "输入删除活动名称" << endl;
    cin >> actName;
    while (info->next != NULL)
    {
        if (info->actName == actName)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        if (info == head)
        {
            if (head->next != NULL)
            {
                head = info->next;
                return head;
            }
            else
            {
                return NULL;


            }
        }
        else if (info->next == NULL)
        {
            actInfo* temp = head;
            while (temp->next != NULL)
            {
                if ((temp->next)->actName == actName)
                {
                    temp->next = NULL;
                    return head;
                }
                temp = temp->next;
            }
        }
        else
        {
            actInfo* temp = head;
            while ((temp->next)->actName != actName)
            {
                temp->next = (temp->next)->next;
                temp = temp->next;
            }
            return head;
        }
    }
    else
    {
        cout << "未找到名称为" << actName << "的活动" << endl;
        return NULL;
    }
}
typedef struct corInfo {
public:    
    int corID;
    string corName;
    string corTName;
    string corDate;
    double credit;
    int finish;
    double corScore;
    corInfo* next=NULL;
};
void printcorInfo(corInfo* info)
{
    corInfo* temp=info;
    if (temp == nullptr)
    {
        cout << "无活动信息" << endl;
    }
    else
        while (temp != NULL)
        {
            cout << temp->corID << "\t" << temp->corName << "\t" << temp->corDate << "\t" << temp->corTName << "\t" << temp->credit << "\t" << temp->finish << "\t" << temp->credit << endl;
            temp = temp->next;
        }
}
void addcorInfo(corInfo* info)
{
    if (info != NULL)
    {
        while (info->next != NULL)
        {
            info = info->next;
        }
        corInfo* temp = nullptr;
        string corName, corDate, corTName;
        double corScore, credit;
        int finish, corID;
        cout << "输入课程id 课程名 课程老师 课程学期 课程学分 课程完成情况 课程成绩" << endl;
        cin >> corID >> corName >> corTName >> corDate >> credit >> finish >> corScore;
        temp->corID = corID;
        temp->corName = corName;
        temp->corTName = corTName;
        temp->corDate = corDate;
        temp->credit = credit;
        temp->finish = finish;
        temp->corScore = corScore;
        info->next = temp;
        info = info->next;
        info->next = NULL;
    }
    else
    {
        corInfo* temp = nullptr;
        string corName, corDate, corTName;
        double corScore, credit;
        int finish, corID;
        cout << "输入课程id 课程名 课程老师 课程学期 课程学分 课程完成情况 课程成绩" << endl;
        cin >> corID >> corName >> corTName >> corDate >> credit >> finish >> corScore;
        temp->corID = corID;
        temp->corName = corName;
        temp->corTName = corTName;
        temp->corDate = corDate;
        temp->credit = credit;
        temp->finish = finish;
        temp->corScore = corScore;
        info = temp;
        info->next = NULL;
    }
}
void changecorInfo(corInfo* info)
{
    int corID;
    bool flag = false;
    printcorInfo(info);
    cout << "输入修改课程id" << endl;
    cin >> corID;
    while (info->next != NULL)
    {
        if (info->corID == corID)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        cout << "输入修改后的课程id 课程名 课程老师 课程学期 课程学分 课程完成情况 课程成绩" << endl;
        string corName, corDate, corTName;
        double corScore, credit;
        int finish, corID;
        cin >> corID >> corName >> corTName >> corDate >> credit >> finish >> corScore;
        info->corID = corID;
        info->corName = corName;
        info->corTName = corTName;
        info->corDate = corDate;
        info->credit = credit;
        info->finish = finish;
        info->corScore = corScore;
    }
    else
    {
        cout << "未找到课程id为" << corID << "的课程" << endl;
    }
}
corInfo* deletecorInfo(corInfo* info)
{
    int corID;
    corInfo* head = info;
    bool flag = false;
    printcorInfo(info);
    cout << "输入删除课程" << endl;
    cin >> corID;
    while (info->next != NULL)
    {
        if (info->corID == corID)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        if (info == head)
        {
            if (head->next != NULL)
            {
                head = info->next;
                return head;
            }
            else
            {
                return NULL;
            }
        }
        else if (info->next == NULL)
        {
            corInfo* temp = head;
            while (temp->next != NULL)
            {
                if ((temp->next)->corID == corID)
                {
                    temp->next = NULL;
                    return head;
                }
                temp = temp->next;
            }
        }
        else
        {
            corInfo* temp = head;
            while ((temp->next)->corID != corID)
            {
                temp->next = (temp->next)->next;
                temp = temp->next;
            }
            return head;
        }
    }
    else
    {
        cout << "未找到课程id为" << corID << "的活动" << endl;
        return NULL;
    }
}
typedef struct AVLTreeNode {
    int depth=0;
    int SID=0;
    perInfo* infor1=nullptr;
    actInfo* infor2=nullptr;
    corInfo* infor3=nullptr;
    AVLTreeNode* pLeftChild=nullptr;
    AVLTreeNode* pRightChild=nullptr;
    AVLTreeNode(int Sid,perInfo* info1,actInfo* info2,corInfo* info3) {
        SID = Sid;
        infor1 = info1;
        infor2 = info2;
        infor3 = info3;
    };
};
class AVLTree {
public:
    AVLTree();
    AVLTreeNode* pRoot;
    AVLTreeNode* Insert(AVLTreeNode*& pNode,int SID, perInfo* infor1, actInfo* infor2, corInfo* infor3);
    AVLTreeNode* Search(AVLTreeNode* pNode, int SID);
    AVLTreeNode* Delete(AVLTreeNode*& pNode, int SID);
    AVLTreeNode* GetMiniNum(AVLTreeNode* pNode);
    AVLTreeNode* GetMaxNum(AVLTreeNode* pNode);
    void AddStudent(AVLTreeNode* pNode,int SID);
    void DeleteStudent(AVLTreeNode* pNode,int SID);
    void Preorder(AVLTreeNode* pNode);
    int GetHeight(AVLTreeNode* pNode);
private:
    AVLTreeNode* LeftRotaion(AVLTreeNode* pNode);				
    AVLTreeNode* RightRotation(AVLTreeNode* pNode);				
    AVLTreeNode* LeftRightRotation(AVLTreeNode* pNode);			
    AVLTreeNode* RightLeftRotation(AVLTreeNode* pNode);
};
AVLTree::AVLTree()
{
    pRoot = nullptr;
}
void AVLTree::Preorder(AVLTreeNode* pNode)  //前序遍历
{
    if (pNode != NULL)
    {
        Preorder(pNode->pLeftChild);
        Preorder(pNode->pRightChild);
    }
}
void AVLTree::AddStudent(AVLTreeNode* pNode,int SID)
{
    cout << "输入学生姓名 专业 联系方式 性别" << endl;
    perInfo* temp1;
    temp1 = new perInfo();
    cin >> temp1->sName >> temp1->major >> temp1->phoNum >> temp1->gender;
    AVLTreeNode* temp = new AVLTreeNode(SID,temp1,NULL,NULL);
    this->pRoot=this->Insert(temp,SID,NULL,NULL,NULL);
};
void AVLTree::DeleteStudent(AVLTreeNode* pNode,int ID)
{
    if (ID < 1e5)
    {
        int temp=0;
        for (int i = 1; i < 1e2; i++)
        {
            temp = i + ID * 100;
            this->pRoot = this->Delete(this->pRoot, temp);
        }
    }
    else
    {
        this->pRoot = this->Delete(this->pRoot,ID);
    }
};
AVLTreeNode* AVLTree::LeftRotaion(AVLTreeNode* pNode)
{
    AVLTreeNode* pRChlid = pNode->pRightChild;
    pNode->pRightChild = pRChlid->pLeftChild;
    pRChlid->pLeftChild = pNode;

    pNode->depth = max(GetHeight(pNode->pLeftChild), GetHeight(pNode->pRightChild)) + 1;
    pRChlid->depth = max(GetHeight(pRChlid->pLeftChild), GetHeight(pRChlid->pRightChild)) + 1;

    return pRChlid;
}
AVLTreeNode* AVLTree::RightRotation(AVLTreeNode* pNode)
{
    AVLTreeNode* pLChild = pNode->pLeftChild;
    pNode->pLeftChild = pLChild->pRightChild;
    pLChild->pRightChild = pNode;

    pNode->depth = max(GetHeight(pNode->pLeftChild), GetHeight(pNode->pRightChild)) + 1;
    pLChild->depth = max(GetHeight(pLChild->pLeftChild), GetHeight(pLChild->pRightChild)) + 1;
    return pLChild;
}
AVLTreeNode* AVLTree::LeftRightRotation(AVLTreeNode* pNode)
{
    pNode->pRightChild = RightRotation(pNode->pRightChild);
    return LeftRotaion(pNode);
}
AVLTreeNode* AVLTree::RightLeftRotation(AVLTreeNode* pNode)
{
    pNode->pLeftChild = LeftRotaion(pNode->pLeftChild);
    return RightRotation(pNode);
}
int AVLTree::GetHeight(AVLTreeNode* pNode)
{
    if (pNode == NULL)
        return 0;

    return pNode->depth;
}
AVLTreeNode* AVLTree::Insert(AVLTreeNode*& pNode, int SID, perInfo* infor1, actInfo* infor2, corInfo* infor3)
{
    if (pNode == NULL)
        pNode = new AVLTreeNode(SID,infor1, infor2, infor3);
    else if (pNode->SID > SID)								//	插入值比当前节点的值小，插入到当前节点的左子树
    {
        pNode->pLeftChild = Insert(pNode->pLeftChild, SID,infor1,infor2,infor3);
        if (GetHeight(pNode->pLeftChild) - GetHeight(pNode->pRightChild) == 2)
        {
            if (SID < pNode->pLeftChild->SID)					//	插入到左子树的左孩子节点上，进行右旋
                pNode = RightRotation(pNode);
            else if (SID > pNode->pLeftChild->SID)			//	插入到左子树的左孩子节点上，进行先左旋后右旋
                pNode = LeftRightRotation(pNode);
        }
    }
    else if (pNode->SID < SID)								//	插入值比当前节点的值大，插入到当前节点的右子树
    {
        pNode->pRightChild = Insert(pNode->pRightChild, SID, infor1, infor2, infor3);
        if (GetHeight(pNode->pRightChild) - GetHeight(pNode->pLeftChild) == 2)
        {
            if (SID > pNode->pRightChild->SID)				//	插入到右子树的右节点上，进行左旋
                pNode = LeftRotaion(pNode);
            else if (SID < pNode->pRightChild->SID)
                pNode = LeftRightRotation(pNode);
        }
    }

    pNode->depth = max(GetHeight(pNode->pLeftChild), GetHeight(pNode->pRightChild)) + 1;
    return pNode;
}
AVLTreeNode* AVLTree::Delete(AVLTreeNode*& pNode, int SID)
{
    if (pNode == NULL)
        return NULL;

    if (SID == pNode->SID)									//	找到要删除的节点
    {
        if (pNode->pLeftChild != NULL && pNode->pRightChild != NULL)
        {
            //	左子树比右子树高，在左子树上选择节点进行替换
            if (GetHeight(pNode->pLeftChild) > GetHeight(pNode->pRightChild))
            {
                //	使用左子树的最大节点来代替被删节点，而删除该最大节点
                AVLTreeNode* pNodeTemp = GetMaxNum(pNode->pLeftChild);				//	左子树最大节点
                pNode->SID = pNodeTemp->SID;
                pNode->pLeftChild = Delete(pNode->pLeftChild, pNodeTemp->SID);		//	递归地删除最大节点
            }
            else
            {
                //	使用最小节点来代替被删节点，而删除该最小节点
                AVLTreeNode* pNodeTemp = GetMiniNum(pNode->pRightChild);				//	右子树的最小节点
                pNode->SID = pNodeTemp->SID;
                pNode->pRightChild = Delete(pNode->pRightChild, pNodeTemp->SID);		//	递归地删除最小节点
            }

        }
        else
        {
            AVLTreeNode* pNodeTemp = pNode;
            if (pNode->pLeftChild != NULL)
                pNode = pNode->pLeftChild;

            if (pNode->pRightChild != NULL)
                pNode = pNode->pRightChild;

            delete pNodeTemp;
            pNodeTemp = NULL;
            return pNode;

        }
    }
    else if (SID > pNode->SID)							//	要删除的节点比当前结点大，则在右子树进行查找
    {
        pNode->pRightChild = Delete(pNode->pRightChild, SID);
        if (GetHeight(pNode->pLeftChild) - GetHeight(pNode->pRightChild) == 2)
        {
            if (GetHeight(pNode->pLeftChild->pRightChild) > GetHeight(pNode->pLeftChild->pLeftChild))
                pNode = LeftRightRotation(pNode);
            else
                pNode = RightRotation(pNode);
        }

    }
    else													//	要删除的节点比当前结点小，则在左子树进行查找
    {
        pNode->pLeftChild = Delete(pNode->pLeftChild, SID);
        if (GetHeight(pNode->pLeftChild->pRightChild) > GetHeight(pNode->pLeftChild->pLeftChild))
            pNode = RightLeftRotation(pNode);
        else
            pNode = LeftRotaion(pNode);
    }

    return pNode;
}
AVLTreeNode* AVLTree::GetMaxNum(AVLTreeNode* pNode)
{
    if (pNode == NULL)
        return NULL;

    while (pNode->pRightChild != NULL)
        pNode = pNode->pRightChild;

    return pNode;
}
AVLTreeNode* AVLTree::GetMiniNum(AVLTreeNode* pNode)
{
    if (pNode == NULL)
        return NULL;

    while (pNode->pLeftChild != NULL)
        pNode = pNode->pLeftChild;

    return pNode;
}
AVLTreeNode* AVLTree::Search(AVLTreeNode* pNode, int SID)
{
    while (pNode != NULL)
    {
        if (SID == pNode->SID)
            return pNode;
        if (SID > pNode->SID)
            pNode = pNode->pRightChild;
        else
            pNode = pNode->pLeftChild;
    }
    return NULL;
}
class inputActInfo {
public:
    int SID;
    actInfo* info;
};
void CreateAct(inputActInfo a[])
{
    ifstream inFile;
    inFile.open("03活动信息.txt");
    int n = 0, i = 0;
    actInfo* temphead, * tempChain;
    tempChain = new actInfo();
    inFile >> n;
    a[i].SID = n;
    inFile >> tempChain->actName;
    inFile >> tempChain->actDate;
    inFile >> tempChain->actScore;
    tempChain->next = NULL;
    temphead = tempChain;
    a[i].info = temphead;
    while (!inFile.eof())
    {
        inFile >> n;
        if (n == a[i].SID)
        {
            tempChain = new actInfo();
            inFile >> tempChain->actName;
            inFile >> tempChain->actDate;
            inFile >> tempChain->actScore;
            tempChain->next = NULL;
            temphead->next = tempChain;
            temphead = temphead->next;
        }
        else
        {
            i++;
            a[i].SID = n;
            tempChain = new actInfo();
            inFile >> tempChain->actName;
            inFile >> tempChain->actDate;
            inFile >> tempChain->actScore;
            tempChain->next = NULL;
            temphead = tempChain;
            a[i].info = temphead;
        }
    }
    inFile.close();
}
class inputCorInfo {
public:
    int SID;
    corInfo* info;
};
void CreateCor(inputCorInfo a[])
{
    ifstream inFile;
    inFile.open("02学习信息.txt");
    int n = 0, i = 0;
    corInfo* temphead, * tempChain;
    tempChain = new corInfo();
    inFile >> n;
    a[i].SID = n;
    inFile >> tempChain->corID;
    inFile >> tempChain->corName;
    inFile >> tempChain->corTName;
    inFile >> tempChain->corDate;
    inFile >> tempChain->credit;
    inFile >> tempChain->finish;
    inFile >> tempChain->corScore;
    tempChain->next = NULL;
    temphead = tempChain;
    a[i].info = temphead;
    while (!inFile.eof())
    {
        inFile >> n;
        if (n == a[i].SID)
        {
            tempChain = new corInfo();
            inFile >> tempChain->corID;
            inFile >> tempChain->corName;
            inFile >> tempChain->corTName;
            inFile >> tempChain->corDate;
            inFile >> tempChain->credit;
            inFile >> tempChain->finish;
            inFile >> tempChain->corScore;
            tempChain->next = NULL;
            temphead->next = tempChain;
            temphead = temphead->next;
        }
        else
        {
            i++;
            a[i].SID = n;
            tempChain = new corInfo();
            inFile >> tempChain->corID;
            inFile >> tempChain->corName;
            inFile >> tempChain->corTName;
            inFile >> tempChain->corDate;
            inFile >> tempChain->credit;
            inFile >> tempChain->finish;
            inFile >> tempChain->corScore;
            tempChain->next = NULL;
            temphead = tempChain;
            a[i].info = temphead;
        }
    }
    inFile.close();
}
class inputPerInfo {
public:
    int SID;
    perInfo* info;
};
void CreatePer(inputPerInfo a[])
{
    ifstream inFile;
    inFile.open("01学生信息.txt");
    int i = 0;
    perInfo* temp ;
    while (!inFile.eof())
    {
        temp = new perInfo();
        inFile >> a[i].SID;
        inFile >> temp->sName;
        inFile >> temp->major;
        inFile >> temp->gender;
        inFile >> temp->phoNum;
        a[i].info = temp;
        i++;
    }
}
int menuShow()
{
    int a,b;
    while (true)
    {
        cout << "\t\t学生信息管理系统\n\n\n\t\t选择你的用户类型\n\t\t1.学生\n\t\t2.班主任\n\t\t3.辅导员" << endl;
        cin >> a;
        system("cls");
        if (a == 1)
        {
            while (true) 
            {
                cout << "用户类型:学生\n功能列表：\n\t1.查询学生信息\n\t0.返回" << endl;
                cin >> b;
                if (b == 1)
                {
                    return 11;
                }
                else if (b == 0)
                {
                    break;
                }
                else {
                    cout << "输入不合法" << endl;
                    system("pause");
                    system("cls");
                }
            }
        }
        else if (a == 2)
        {
            while (true)
            {
                cout << "用户类型:班主任\n功能列表：\n\t1.查询学生信息\n\t2.添加学生活动信息\n\t3.更改学生活动信息\n\t0.返回" << endl;
                cin >> b;
                if (b == 1)
                {
                    return 21;
                }
                else if (b == 2)
                {
                    return 23;
                }
                else if (b == 3)
                {
                    system("cls");
                    cout << "选择更改类型:1.更改\t2.删除" << endl;
                    int c;
                    cin >> c;
                    if (c == 1)
                    {
                        return 24;
                    }
                    else if (c == 2)
                    {
                        return 25;
                    }
                    else
                    {
                        cout << "输入不合法" << endl;
                        system("pause");
                        system("cls");
                    }
                }
                else if (b == 0)
                {
                    break;
                }
                else {
                    cout << "输入不合法" << endl;
                    system("pause");
                    system("cls");
                }
            }
        }
        else if (a == 3)
        {
            while (true)
            {
                cout << "用户类型:辅导员\n功能列表：\n\t1.查询学生信息\n\t2.添加学生\n\t3.删除学生\n\t4.添加学生学习信息\n\t5.添加学生活动信息\n\t6.修改学生学习信息\n\t7.修改学生活动信息\n\t0.返回" << endl;
                cin >> b;
                if (b == 1)
                {
                    return 31;
                }
                else if (b == 2)
                {
                    return 33;
                }
                else if (b == 3)
                {
                    return 34;
                }
                else if (b == 4)
                {
                    return 35;
                }
                else if (b == 5)
                {
                    return 36;
                }
                else if (b == 6)
                {
                    system("cls");
                    cout << "选择更改类型:1.更改\t2.删除" << endl;
                    int c;
                    cin >> c;
                    if (c == 1)
                    {
                        return 41;
                    }
                    else if (c == 2)
                    {
                        return 42;
                    }
                    else
                    {
                        cout << "输入不合法" << endl;
                        system("pause");
                        system("cls");
                    }
                }
                else if (b == 7)
                {
                    system("cls");
                    cout << "选择更改类型:1.更改\t2.删除" << endl;
                    int c;
                    cin >> c;
                    if (c == 1)
                    {
                        return 43;
                    }
                    else if (c == 2)
                    {
                        return 44;
                    }
                    else
                    {
                        cout << "输入不合法" << endl;
                        system("pause");
                        system("cls");
                    }
                }
                else if (b == 0)
                {
                    break;
                }
                else {
                    cout << "输入不合法" << endl;
                    system("pause");
                    system("cls");
                }
            }
        }
        else
        {
            cout << "输入不符合规则" << endl;
        }
    }
}
void choose(int input, AVLTree A)
{
    int SID;
    AVLTreeNode* temp;
    if (input == 11)
    {
        cout << "输入学号" << endl;
        cin >> SID;
        temp = A.Search(A.pRoot, SID);
        if (temp == NULL)
        {
            cout << "未找到对应用户" << endl;
            system("pause");
            return;
        }
        else {
        system("cls");
        cout << "学号\t姓名\t专业\t联系方式\t性别" << endl;
        cout << temp->SID << "\t" << temp->infor1->sName << "\t" << temp->infor1->major << "\t" << temp->infor1->phoNum << "\t" << temp->infor1->gender << endl;
        cout << "课程编号\t课程名称\t任课老师\t选修时间\t学分\t完成情况\t成绩" << endl;
        corInfo* tempCor = temp->infor3;
        while (tempCor != NULL)
        {
            cout << tempCor->corID << "\t" << tempCor->corName << "\t" << tempCor->corTName << "\t" << tempCor->corDate << "\t" << tempCor->credit << "\t" << tempCor->finish << "\t" << tempCor->corScore << endl;
            tempCor = tempCor->next;
        }
        cout << "活动名称\t活动时间\t综测分" << endl;
        actInfo* tempAct = temp->infor2;
        while (tempAct != NULL)
        {
            cout << tempAct->actName << "\t" << tempAct->actDate << "\t" << tempAct->actScore << endl;
            tempAct = tempAct->next;
        }
    }
    }
    //学生查询信息
    
    if (input == 21) {
        cout << "输入学生学号或输入班级号";
        cin >> SID;
        system("cls");
        cout << "学号\t姓名\t专业\t联系方式\t性别" << endl;
        if (SID < 1e5)
        {
            int a = 0;
            for (int i = 1; i < 1e2; i++)
            {
                a = i + SID * 100;
                temp = A.Search(A.pRoot, a);
                if (temp == NULL)
                {
                    cout << "未找到对应用户" << endl;
                    system("pause");
                    return;
                }
                else
                cout << temp->SID << "\t" << temp->infor1->sName << "\t" << temp->infor1->major << "\t" << temp->infor1->phoNum << "\t" << temp->infor1->gender << endl;
            }
        }
        else
        {
            temp = A.Search(A.pRoot, SID);
            if (temp == NULL)
            {
                cout << "未找到对应用户" << endl;
                system("pause");
                return;
            }
            else
            {
                cout << "课程编号\t课程名称\t任课老师\t选修时间\t学分\t完成情况\t成绩" << endl;
                corInfo* tempCor;
                tempCor = temp->infor3;
                while (tempCor != NULL)
                {
                    cout << tempCor->corID << "\t" << tempCor->corName << "\t" << tempCor->corTName << "\t" << tempCor->corDate << "\t" << tempCor->credit << "\t" << tempCor->finish << "\t" << tempCor->corScore << endl;
                    tempCor = tempCor->next;
                }
                cout << "活动名称\t活动时间\t综测分" << endl;
                actInfo* tempAct;
                tempAct = temp->infor2;
                while (tempAct != NULL)
                {
                    cout << tempAct->actName << "\t" << tempAct->actDate << "\t" << tempAct->actScore << endl;
                    tempAct = tempAct->next;
                }
            }
        }
    }
    //班主任查询学生信息
    

    if (input == 23) {
        cout << "输入学生学号";
        cin >> SID;
        system("cls");
        temp = A.Search(A.pRoot, SID);
        if (temp == NULL)
        {
           cout << "未找到对应用户" << endl;
           system("pause");
           return;
        }
           else
           addactInfo(temp->infor2);
    }
    //班主任添加活动信息
    if (input == 24) {
        cout << "输入学生学号";
        cin >> SID;
        system("cls");
        temp = A.Search(A.pRoot, SID);
        if (temp == NULL)
        {
            cout << "未找到对应用户" << endl;
            system("pause");
            return;
        }
        else
            changeactInfo(temp->infor2);
    }//班主任更改活动信息
    if (input == 25) {
        cout << "输入学生学号";
        cin >> SID;
        system("cls");
        temp = A.Search(A.pRoot, SID);
        if (temp == NULL)
        {
            cout << "未找到对应用户" << endl;
            system("pause");
            return;
        }
        else
            temp->infor2=deleteactInfo(temp->infor2);
    }//班主任删除活动信息
    if (input == 31) {
        cout << "输入学生学号或输入班级号";
        cin >> SID;
        system("cls");
        cout << "学号\t姓名\t专业\t联系方式\t性别" << endl;
        if (SID < 1e5)
        {
            int a = 0;
            for (int i = 1; i < 1e2; i++)
            {
                a = i + SID * 100;
                temp = A.Search(A.pRoot, a);
                if (temp == NULL)
                {
                    cout << "未找到对应用户" << endl;
                    system("pause");
                    return;
                }
                else
                    cout << temp->SID << "\t" << temp->infor1->sName << "\t" << temp->infor1->major << "\t" << temp->infor1->phoNum << "\t" << temp->infor1->gender << endl;
            }
        }
        else
        {
            temp = A.Search(A.pRoot, SID);
            if (temp == NULL)
            {
                cout << "未找到对应用户" << endl;
                system("pause");
                return;
            }
            else
            {
                cout << "课程编号\t课程名称\t任课老师\t选修时间\t学分\t完成情况\t成绩" << endl;
                while (temp->infor3->next != NULL)
                {
                    cout << temp->infor3->corID << "\t" << temp->infor3->corName << "\t" << temp->infor3->corTName << "\t" << temp->infor3->corDate << "\t" << temp->infor3->credit << "\t" << temp->infor3->finish << "\t" << temp->infor3->corScore << endl;
                    temp->infor3 = temp->infor3->next;
                }
                cout << "活动名称\t活动时间\t综测分" << endl;
                while (temp->infor2->next != NULL)
                {
                    cout << temp->infor2->actName << "\t" << temp->infor2->actDate << "\t" << temp->infor2->actScore << endl;
                    temp->infor2 = temp->infor2->next;
                }
            }
        }
    }//辅导员查询信息


    if (input == 33) {
        cout << "输入学生学号";
        cin >> SID;
        system("cls");
        A.AddStudent(A.pRoot, SID);
    }//辅导员添加学生
    if (input == 34) {
        cout << "输入学生学号";
        cin >> SID;
        system("cls");
        temp = A.Search(A.pRoot, SID);
        if (temp == NULL)
        {
            cout << "未找到对应用户" << endl;
            system("pause");
            return;
        }
        else
            addcorInfo(temp->infor3);
    }//辅导员添加学习信息
    if (input == 35) {
        cout << "输入学生学号";
        cin >> SID;
        system("cls");
        temp = A.Search(A.pRoot, SID);
        if (temp == NULL)
        {
            cout << "未找到对应用户" << endl;
            system("pause");
            return;
        }
        else
            addcorInfo(temp->infor3);
    }//辅导员添加学习信息
    if (input == 36) {
        cout << "输入学生学号";
        cin >> SID;
        system("cls");
        temp = A.Search(A.pRoot, SID);
        if (temp == NULL)
        {
            cout << "未找到对应用户" << endl;
            system("pause");
            return;
        }
        else
            addactInfo(temp->infor2);
    }//辅导员添加活动信息
    if (input == 41) {
        cout << "输入学生学号";
        cin >> SID;
        system("cls");
        temp = A.Search(A.pRoot, SID);
        if (temp == NULL)
        {
            cout << "未找到对应用户" << endl;
            system("pause");
            return;
        }
        else
            changecorInfo(temp->infor3);
    }
    if (input == 42) {
        cout << "输入学生学号";
        cin >> SID;
        system("cls");
        temp = A.Search(A.pRoot, SID);
        if (temp == NULL)
        {
            cout << "未找到对应用户" << endl;
            system("pause");
            return;
        }
        else
            temp->infor3 = deletecorInfo(temp->infor3);
    }
    if (input == 43) {
        cout << "输入学生学号";
        cin >> SID;
        system("cls");
        temp = A.Search(A.pRoot, SID);
        if (temp == NULL)
        {
            cout << "未找到对应用户" << endl;
            system("pause");
            return;
        }
        else
            changeactInfo(temp->infor2);
    }
    if (input == 44) {
        cout << "输入学生学号";
        cin >> SID;
        system("cls");
        temp = A.Search(A.pRoot, SID);
        if (temp == NULL)
        {
            cout << "未找到对应用户" << endl;
            system("pause");
            return;
        }
        else
            temp->infor2 = deleteactInfo(temp->infor2);
    }
}
int main()
{
    inputActInfo Act[MAXSIZE];
    CreateAct(Act);
    inputPerInfo Per[MAXSIZE];
    CreatePer(Per);
    inputCorInfo Cor[MAXSIZE];
    CreateCor(Cor);
    AVLTree* pTree = new AVLTree();
    actInfo* temp1;
    corInfo* temp2;
    for (int i = 0;i < MAXSIZE;i++)
    {
        int t;
        t = Per->SID;
        if (Per->SID == 0)
        {
            break;
        }
        else
        {
            for (int j = 0; j < MAXSIZE; j++)
            {
                if (Act->SID == 0)
                {
                    break;
                }
                else if (Act->SID == t)
                {
                    temp1 = Act->info;
                    break;
                }
            }
            for (int j = 0; j < MAXSIZE; j++)
            {
                if (Cor->SID == 0)
                {
                    break;
                }
                else if (Cor->SID == t)
                {
                    temp2 = Cor->info;
                    break;
                }
            }
            pTree->Insert(pTree->pRoot, Per->SID, Per->info, Act->info, Cor->info);
        }
    }
    while (true)
    {
        int input;
        input=menuShow(); 
        system("cls");
        choose(input, *pTree);
        system("pause");
        system("cls");
    }
}