#include <iostream>
#include "PriorityQueue.h"
#include "Node.h"

using namespace std;

int PriorityQueue::Count()
{
    return heap.size();
}

Node* PriorityQueue::FindNode(Node& n)
{
    for (int i = 0; i < heap.size(); i++)
    {
        if (heap[i].point.x == n.point.x && heap[i].point.y == n.point.y)
            return &heap[i];
    }
    return NULL;
}

void PriorityQueue::Push(Node data)
{
    heap.push_back(data);
    int now = heap.size() - 1; //���� �ε���
    while (now > 0)
    {
        int next = (now - 1) / 2; //�θ� �����ؼ� ���Ѵ� (Ÿ��ĳ��Ʈ�� �ڵ� ���� ��)
        if (heap[now].Compare(heap[next]) < 0)  //next�� now���� �� �������
        {
            break;
        }
        
        Node temp = heap[now];
        heap[now] = heap[next];
        heap[next] = temp;
        now = next;
    }
}

Node PriorityQueue::Pop()
{
    Node ret = heap[0];

    int lastIdx = heap.size() - 1;
    heap[0] = heap[lastIdx];
    heap.pop_back(); //������ ���� ����
    lastIdx--;

    int now = 0; //�������鼭 �ڱ� ���� ã�ư���
    while (true)
    {
        int left = 2 * now + 1;
        int right = 2 * now + 2;

        int next = now;

        if (left <= lastIdx && heap[next].Compare(heap[left]) < 0)
        {
            next = left;
        }

        if (right <= lastIdx && heap[next].Compare(heap[right]) < 0)
        {
            next = right;
        }

        if (next == now) //�ڱ� �ڸ� ã�Ҿ�
        {
            break;
        }

        Node temp = heap[now];
        heap[now] = heap[next];
        heap[next] = temp;
        now = next;
    }

    return ret;
}

void PriorityQueue::PrintHeap()
{
    for (int i = 0; i < heap.size(); i++)
    {
        cout << heap[i].ToString() << endl;
    }
}
