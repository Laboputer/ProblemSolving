class AuthenticationManager {
public:
	map<string, int> tokens;
	int X;

	AuthenticationManager(int timeToLive) {
		X = timeToLive;
	}

	void generate(string tokenId, int currentTime) {
		tokens[tokenId] = currentTime + X;
	}

	void renew(string tokenId, int currentTime) {
		map<string, int>::iterator pos = tokens.find(tokenId);
		if (pos != tokens.end())
		{
			if (pos->second <= currentTime) tokens.erase(tokenId);
			else pos->second = currentTime + X;
		}
	}

	int countUnexpiredTokens(int currentTime) {
		vector<map<string, int>::iterator> eraseList;
		for (map<string, int>::iterator it = tokens.begin(); it != tokens.end(); it++)
			if (it->second <= currentTime) eraseList.push_back(it);

		for (int i = 0; i < eraseList.size(); i++) tokens.erase(eraseList[i]);

		return tokens.size();
	}
};