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
    if (info == nullptr)
    {
        cout << "无活动信息" << endl;
    }
    else
        while (info->next != NULL)
        {
            cout << info->actName << "\t" << info->actDate << "\t" << info->actScore << endl;
            info = info->next;
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
    if (info == nullptr)
    {
        cout << "无活动信息" << endl;
    }
    else
        while (info->next != NULL)
        {
            cout << info->corID << "\t" << info->corName << "\t" << info->corDate << "\t" << info->corTName << "\t" << info->credit << "\t" << info->finish << "\t" << info->credit << endl;
            info = info->next;
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
void printavr(corInfo* info)
{
    int n = 0;
    double sum = 0;
    if (info == nullptr)
    {
        cout << "不存在学习信息无法计算" << endl;
    }
    else
    {
        while (info->next != NULL)
        {
            if (info->finish == 1)
            {
                n++;
                sum += info->corScore;
            }
            info = info->next;
        }
        if (n == 0)
        {
            cout << "无完成课程，无法计算" << endl;
        }
        else
            cout << "平均成绩为" << sum / n<<endl;
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
    AVLTreeNode* pRoot;
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
    AVLTreeNode* temp = new AVLTreeNode(SID,NULL,NULL,NULL);
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
}
class inputperInfo {
    int SID;
    perInfo* info;
};
int main()
{
    inputActInfo a[2];
    CreateAct(a);
    inputCorInfo b[2];
    CreateCor(b);
    cout << b[1].info->corName;
}