#define MOD 1000000007ll
class Solution {
public:
	struct order
	{
		int price;
		int amount;
		bool operator < (const order& rhs) const
		{
			return price < rhs.price;
		}
	};

    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
		priority_queue<order> buy, sell;
		for(int i=0; i<orders.size(); i++)
		{
			int p = orders[i][0], a = orders[i][1];
			if(orders[i][2])
			{
				while(a > 0 && !buy.empty() && buy.top().price >= p)
				{
					order top = buy.top(); buy.pop();
					a -= top.amount;
					if(a < 0)
					{
						top.amount = -a;
						buy.push(top);
					}
				}
				if(a > 0) sell.push({-p, a});
			}
			else
			{
				while(a > 0 && !sell.empty() && -sell.top().price <= p)
				{
					order top = sell.top(); sell.pop();
					a -= top.amount;
					if(a < 0)
					{
						top.amount = -a;
						sell.push(top);
					}
				}
				if(a > 0) buy.push({p, a});
			}
		}

		int sum = 0;
		while(!buy.empty()) sum = (sum + buy.top().amount) % MOD, buy.pop();
		while(!sell.empty()) sum = (sum + sell.top().amount) % MOD, sell.pop();
		return sum;
    }
};