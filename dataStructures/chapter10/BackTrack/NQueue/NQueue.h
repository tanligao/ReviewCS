#ifndef __NQUEUE_H
#define __NQUEUE_H

class NQueue
{
public:
	NQueue(int length = 4);
	~NQueue();

	inline int sum() { return _sum; }
	void BackTrack(int k);
	void NBackTrack();
private:
	bool Place(int k);

	int *_x;
	int _length;
	int _sum;
};

#endif /* __NQUEUE_H */