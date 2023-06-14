#include <iostream>
#include "PriorityQueue.h"
#include "Common.h"
#include "Node.h"

using namespace std;

PriorityQueue::PriorityQueue()
{
}

PriorityQueue::~PriorityQueue()
{
    for (auto it = heap.begin(); it != heap.end(); ++it)
    {
        delete* it;
    }
}

int PriorityQueue::Count()
{
    return heap.size();
}

Node* PriorityQueue::FindNode(Node& n)
{
    for (int i = 0; i < heap.size(); i++)
    {
        if (*heap[i]->point == *n.point)
            return heap[i];
    }
    return nullptr;
}

void PriorityQueue::Push(Node data)
{
    Node* insertNode = new Node(data);
    heap.push_back(insertNode);
    int now = heap.size() - 1; //현재 인덱스
    while (now > 0)
    {
        int next = (now - 1) / 2; //부모를 선택해서 비교한다 (타입캐스트로 자동 내림 돼)
        if (heap[now]->Compare(heap[next]) < 0)  //next가 now보다 더 작은경우
        {
            break;
        }
        
        Node* temp = heap[now];
        heap[now] = heap[next];
        heap[next] = temp;
        now = next;
    }
}

Node* PriorityQueue::Pop()
{
    Node* ret = heap[0];

    int lastIdx = heap.size() - 1;
    heap[0] = heap[lastIdx];
    heap.pop_back(); //마지막 원소 제거
    lastIdx--;

    int now = 0; //내려가면서 자기 차리 찾아가기
    while (true)
    {
        int left = 2 * now + 1;
        int right = 2 * now + 2;

        int next = now;

        if (left <= lastIdx && heap[next]->Compare(heap[left]) < 0)
        {
            next = left;
        }

        if (right <= lastIdx && heap[next]->Compare(heap[right]) < 0)
        {
            next = right;
        }

        if (next == now) //자기 자리 찾았어
        {
            break;
        }

        Node* temp = heap[now];
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
        cout << heap[i]->ToString() << endl;
    }
}
