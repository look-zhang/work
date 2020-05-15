#include <iostream>
#include <iomanip>
using namespace std;
typedef char ElemType;
typedef struct LNode

//单链表的存储结构定义
{
    ElemType data;//数据域
    struct LNode *next;//指针域
}LNode, * Linklist;


Linklist create_L(int n)//逆序创建单链表
{
    Linklist L, p;
    int i;
    L = new LNode;
    L->next = NULL;
    cout << "input numbers in list";
    for (i = n; i > 0; --i)
    {
        p = new LNode;
        cin >> p->data;//输出数据放在节点指针p的数据域
        p->next = L->next;//将指针p所指节点插到L节点的后面
        L->next = p;//将指针p所指节点插到L节点后面
    }
    return(L);


}
void print_L(Linklist L)
{
    Linklist p;
    cout << "\nThe list is:\n";
    p = L ->next;
    while(p)
    {
        cout << setw(3) <<p->data;

        p = p->next;//指针p后移一个节点
    }
    cout << endl;
}


int ListInsert_L(Linklist L, int i, ElemType x)
{
    Linklist p, s;
    int j;
    p = L; j = 0;
    while(p&&j<i-1)//寻找地i-1个节点
    {
        p = p->next; ++j;
    }
    if (!p || j > i - 1)
        return 0; //i小于或大于表长，则返回
    s = new LNode; //生成新的数据域
    s->data = x;//将数据x放到s的数据域
    s->next = p->next;//在节点p后面插入节点s
    p->next = s;//在节点p后面插入节点s
    return 1;
}


void ListDelete_X(Linklist L, ElemType x)
{
    Linklist p,q;
    p = L;
    q = p->next;//移动指针q到后一个节点
    while (q && q->data != x)
    {
        p = q;
        q = q->next;
    }
    if (q)
    {
        p->next = q->next;
        delete(q);//删除q所指向的节点
    }
    else cout << x << "does not exist!" << endl;
}


int Locate_X(Linklist L, ElemType x)
{
    int i = 0;
    Linklist p;
    p = L->next;
    while (p)
    {
        i++;
        if (p->data == x)break;
        p = p->next;
    }
    if (p) return i;
    else return 0;
}

int main()
{
    int n, i;
    ElemType x;
    Linklist L;
    cout << "Please enter the length of the created linear table n. \ninput n:";
    cin >> n; //输入线性表中元素的个数
    L = create_L(n); //按逆位序创建线性表 L
    print_L(L); //打印线性表 L
    cout << "Enter the position I to insert and the number x to insert \ninput i,x:"; //输入要插入的位置 i 和要插入的数 x
    cin >> i >> x;
    ListInsert_L(L, i, x);//将 x 插入在 L 的第 i 个位置
    print_L(L);
    cout << "Enter the number x to delete \ninput x:";
    cin >> x; //输入要删除的数 x
    ListDelete_X(L, x); //在线性表 L 中删除第一个值为 x 的结点
    print_L(L);

    //打印删除后的线性表
    cout << "Enter the number x to find \ninput x:"; //输入要查找的数 x
    cin >> x;
    i = Locate_X(L, x); //查找 x 在 L 中的位置 i
    cout << "\nposition of " << x << " is " << i << endl;
    return 0;
}


