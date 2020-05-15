#include <iostream>
#include <iomanip>
using namespace std;
typedef char ElemType;
typedef struct LNode

//������Ĵ洢�ṹ����
{
    ElemType data;//������
    struct LNode *next;//ָ����
}LNode, * Linklist;


Linklist create_L(int n)//���򴴽�������
{
    Linklist L, p;
    int i;
    L = new LNode;
    L->next = NULL;
    cout << "input numbers in list";
    for (i = n; i > 0; --i)
    {
        p = new LNode;
        cin >> p->data;//������ݷ��ڽڵ�ָ��p��������
        p->next = L->next;//��ָ��p��ָ�ڵ�嵽L�ڵ�ĺ���
        L->next = p;//��ָ��p��ָ�ڵ�嵽L�ڵ����
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

        p = p->next;//ָ��p����һ���ڵ�
    }
    cout << endl;
}


int ListInsert_L(Linklist L, int i, ElemType x)
{
    Linklist p, s;
    int j;
    p = L; j = 0;
    while(p&&j<i-1)//Ѱ�ҵ�i-1���ڵ�
    {
        p = p->next; ++j;
    }
    if (!p || j > i - 1)
        return 0; //iС�ڻ���ڱ����򷵻�
    s = new LNode; //�����µ�������
    s->data = x;//������x�ŵ�s��������
    s->next = p->next;//�ڽڵ�p�������ڵ�s
    p->next = s;//�ڽڵ�p�������ڵ�s
    return 1;
}


void ListDelete_X(Linklist L, ElemType x)
{
    Linklist p,q;
    p = L;
    q = p->next;//�ƶ�ָ��q����һ���ڵ�
    while (q && q->data != x)
    {
        p = q;
        q = q->next;
    }
    if (q)
    {
        p->next = q->next;
        delete(q);//ɾ��q��ָ��Ľڵ�
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
    cin >> n; //�������Ա���Ԫ�صĸ���
    L = create_L(n); //����λ�򴴽����Ա� L
    print_L(L); //��ӡ���Ա� L
    cout << "Enter the position I to insert and the number x to insert \ninput i,x:"; //����Ҫ�����λ�� i ��Ҫ������� x
    cin >> i >> x;
    ListInsert_L(L, i, x);//�� x ������ L �ĵ� i ��λ��
    print_L(L);
    cout << "Enter the number x to delete \ninput x:";
    cin >> x; //����Ҫɾ������ x
    ListDelete_X(L, x); //�����Ա� L ��ɾ����һ��ֵΪ x �Ľ��
    print_L(L);

    //��ӡɾ��������Ա�
    cout << "Enter the number x to find \ninput x:"; //����Ҫ���ҵ��� x
    cin >> x;
    i = Locate_X(L, x); //���� x �� L �е�λ�� i
    cout << "\nposition of " << x << " is " << i << endl;
    return 0;
}


