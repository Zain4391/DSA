#include<iostream>
#include<queue>
using namespace std;

class MovingAverage
{
    int ws; //window size
    queue <int> q;

    public:
    MovingAverage(int k)
    {
        ws = k;
    }

    float next(int n)
    {
        queue<int> temp;
        float sum = 0;
        q.push(n);
        if(q.size() > ws)
        {
            q.pop();
        }
        
        while(!q.empty())
        {
            int val = q.front();
            q.pop();
            temp.push(val);
            sum+=val;
        }

        while(!temp.empty())
        {
            q.push(temp.front());
            temp.pop();
        }

        return (sum/q.size());
    }
};

int main()
{
    MovingAverage mv(3);
    cout<<mv.next(1)<<endl;
    cout<<mv.next(10)<<endl;
    cout<<mv.next(3)<<endl;

    return 0;
}