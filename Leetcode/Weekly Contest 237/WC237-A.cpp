class Solution {
public:
	bool checkIfPangram(string sentence) {
		int c[26] = { 0, };
		for (int i = 0; i < sentence.size(); i++)
			c[sentence[i] - 'a'] = 1;
		
		int sum = 0;
		for (int i = 0; i < 26; i++)
			sum += c[i];
		return sum == 26;
	}
};