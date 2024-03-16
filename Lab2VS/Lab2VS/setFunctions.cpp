#include "setFunctions.h"
#include "set.h"
#include "set.cpp"
#include <cmath>

using namespace std;
// Returns a set that is the Union of the two sets s1 and s2
Set<char> setUnion(const Set<char>& s1, const Set<char>& s2)
{
	Set<char> result;

	// Add your code here
	int i = 0;
	for (i = 0; i < s1.cardinality(); ++i) {
		result.insertElement(s1[i]);
	}
	for (i = 0; i < s2.cardinality(); ++i) {
		result.insertElement(s2[i]);
	}

	return result;
}

// Returns a set that is the intersection of the two sets s1 and s2
Set<char> setIntersection(const Set<char>& s1, const Set<char>& s2)
{
	Set<char> result;
	int i = 0;
	for (i = 0; i < s1.cardinality(); ++i) {
		if (s2.isElement(s1[i])) {
			result.insertElement(s1[i]);
		}
	}
	// Add your code here

	return result;
}

// Returns a set that is the s1 - s2
Set<char> setDiff(const Set<char>& s1, const Set<char>& s2)
{
	Set<char> result;
	int i = 0;
	for (i = 0; i < s1.cardinality(); ++i) {
		if (!s2.isElement(s1[i])) {
			result.insertElement(s1[i]);
		}
	}
	// Add your code here

	return result;
}

// Returns a set that is the symetric difference of the two sets s1 and s2
Set<char> setSymDiff(const Set<char>& s1, const Set<char>& s2)
{
	Set<char> result;
	int i = 0;
	for (i = 0; i < s1.cardinality(); ++i) {
		if (!s2.isElement(s1[i])) {
			result.insertElement(s1[i]);
		}
	}
	for (i = 0; i < s2.cardinality(); ++i) {
		if (!s1.isElement(s2[i])) {
			result.insertElement(s2[i]);
		}
	}
	// Add your code here

	return result;
}

// Returns true if s1 is a subset of s2
bool isSubSet(const Set<char>& s1, const Set<char>& s2)
{
	if (s1.cardinality() <= s2.cardinality()) {
		int i = 0;
		for (i = 0; i < s1.cardinality(); ++i) {
			if (!s2.isElement(s1[i])) {
				return false;
			}
		}
	}
	else {
		return false;
	
	}
	// Add your code here and return the correct truth value
	return true;
}

// Returns true if s1 is a proper subset of s2
bool isProperSubSet(const Set<char>& s1, const Set<char>& s2)
{
	if (s1.cardinality() < s2.cardinality()) {
		int i = 0;
		for (i = 0; i < s1.cardinality(); ++i) {
			if (!s2.isElement(s1[i])) {
				return false;
			}
		}
	}
	else {
		return false;

	}
	// Add your code here and return the correct truth value
	return true;
}

// Returns the Power Set of set s as a set of sets
Set<Set<char>> PowerSet(const Set<char>& s)
{
	Set<Set<char>> result;
	vector<int> indicesStamp;
	int setSize;
	int ogSize = s.cardinality();

	result.insertElement(Set<char>());
	for (setSize = 1; setSize < ogSize; ++setSize) {
		int i;
		for (i = 0; i < setSize; ++i) {
			if (i >= indicesStamp.size()) {
				indicesStamp.push_back(i);
			}
			else {
				indicesStamp[i] = i;
			}
		}
		int amountOfSubsets = std::tgamma(ogSize + 1) / (std::tgamma(setSize + 1) * std::tgamma(ogSize - setSize + 1));
		for (i = 0; i < amountOfSubsets; ++i) {
			Set<char> subset;
			int j;
			for (j = 0; j < setSize; ++j) {
				subset.insertElement(s[indicesStamp[j]]);
			}
			result.insertElement(Set<char>(subset));
			j = 1;
			while (j <= setSize) {
				if (indicesStamp[setSize - j] < (ogSize - j)) {
					++indicesStamp[(setSize - j)];
					break;
				}
				else {
					++j;
				}
			}
		}
	}
	// Add your code here
	result.insertElement(s);
	return result;
}

// Returns true if the sets in p make up a Partition of set s
bool isPartition(const Set<Set<char>>& p, const Set<char>& s)
{
	// Add your code here and return the correct truth value
	int i = 0;
	for (i = 0; i < p.cardinality(); ++i) {
		if (!isProperSubSet(p[i], s)) {
			return false;
		}
		if (i > 0) {
			int j = 0;
			for (j = 0; j < i; ++j) {
				if (setIntersection(p[i], p[j]).cardinality() > 0) {
					return false;
				}
			}
		}
	}
	return true;
}