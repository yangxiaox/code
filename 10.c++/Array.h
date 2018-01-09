#include <iostream>
#include <cstdio>

#define OK 1
#define ERROR 0
#define MAXSIZE 100
char p[10][7][4] = { { '0','0','0','0','0',' ',' ','0','0',' ',' ','0','0',' ',' ','0','0',' ',' ','0','0',' ',' ','0','0','0','0','0' },
{ ' ',' ','1',' ',' ','1','1',' ',' ',' ','1',' ',' ',' ','1',' ',' ',' ','1',' ',' ',' ','1',' ',' ','1','1','1' },
{ '2','2','2','2',' ',' ',' ','2',' ',' ',' ','2','2','2','2','2','2',' ',' ',' ','2',' ',' ',' ','2','2','2','2' },
{ '3','3','3','3',' ',' ',' ','3',' ',' ',' ','3','3','3','3','3',' ',' ',' ','3',' ',' ',' ','3','3','3','3','3' },
{ '4',' ',' ','4','4',' ',' ','4','4',' ',' ','4','4','4','4','4',' ',' ',' ','4',' ',' ',' ','4',' ',' ',' ','4' },
{ '5','5','5','5','5',' ',' ',' ','5',' ',' ',' ','5','5','5','5',' ',' ',' ','5',' ',' ',' ','5','5','5','5','5' },
{ '6','6','6','6','6',' ',' ',' ','6',' ',' ',' ','6','6','6','6','6',' ',' ','6','6',' ',' ','6','6','6','6','6' },
{ '7','7','7','7',' ',' ',' ','7',' ',' ',' ','7',' ',' ',' ','7',' ',' ',' ','7',' ',' ',' ','7',' ',' ',' ','7' },
{ '8','8','8','8','8',' ',' ','8','8',' ',' ','8','8','8','8','8','8',' ',' ','8','8',' ',' ','8','8','8','8','8' },
{ '9','9','9','9','9',' ',' ','9','9',' ',' ','9','9','9','9','9',' ',' ',' ','9',' ',' ',' ','9','9','9','9','9' }
};
template<typename T>
class my_vector {
public:
	//my_vector(int size = 100);
    my_vector(int size = 100) : size(size) , now(0) {
	    data = new T[size];
    }
	//my_vector(int *data , int data_size);
	~my_vector();
	
	my_vector(const my_vector &another);

	inline std::size_t length()const;
	inline void push_back(T newdata);

	inline const T operator [](int index)const ;
	inline T & operator [] (int index);
	inline my_vector operator + (const my_vector& another);
	inline bool operator == (const my_vector& another)const;
	inline my_vector<T> &operator = (const my_vector& another);
	inline void out()const;

	int now;
private:
	T *data;
	int size;
	my_vector<T> *next;

};
/*
template<typename T>
my_vector<T>::my_vector(int size = 100) : size(size) , now(0) {
	data = new T[size];
}*/
/*
template<typename T>
inline my_vector<T>::my_vector(int * data , int data_size)
{
	data = new T[data_size];
	size = data_size;
	for (now = 0; now < data_size; ++now) {
		this->data[now] = data[now];
	}
}
*/
template<typename T>
my_vector<T>::~my_vector() {
	delete[] data;
}
template<typename T>
my_vector<T>::my_vector(const my_vector &another) {
	size = another.length();
	data = new T[size];
	now = 0;
	for(now = 0 ; now < another.now ; ++now){
		data[now] = another[now];
	}
}

template<typename T>
inline std::size_t my_vector<T>::length() const
{
	return (std::size_t)now;
}

template<typename T>
inline void my_vector<T>::push_back(T newdata)
{
	if (now + 1 == size) {
		T *newdata = new T[size + 100];
		for (int i = 0; i < size; ++i) {
			newdata[i] = data[i];
		}
		size += 100;
		delete[]data;
		data = newdata;
	}
	data[now++] = newdata;
}
template<typename T>
inline const T my_vector<T>::operator[](int index) const
{
	if (index < 0 || index >= size) {
		printf("∑√Œ Œﬁ–ß\n");
	}
	return data[index];
}

template<typename T>
inline T & my_vector<T>::operator[](int index)
{
	return const_cast<T&>(static_cast<const T&>((this->data)[index]));
}

template<typename T>
inline my_vector<T> my_vector<T>::operator + (const my_vector &another)
{
	my_vector<T> new_vector(size + another.size);
	for (int i = 0; i < now; ++i) {
		new_vector.push_back(data[i]);
	}
	for (int i = 0; i < another.now; ++i) {
		new_vector.push_back(another.data[i]);
	}
	return new_vector;
}

template<typename T>
inline bool my_vector<T>::operator == (const my_vector & another) const
{
	if (now < another.now || another.now > now) {
		return false;
	}
	for (int i = 0; i < size; ++i) {
		if (data[i] != another.data[i]) {
			return false;
		}
	}
	return true;
}

template<typename T>
inline my_vector<T> &my_vector<T>::operator = (const my_vector &another)
{
	if (this != &another)
	{
		delete[] data;
		data = new T[another.size];
		for (now = 0; now < another.now; ++now) {
			data[now] = another.data[now];
		}
	}
	return *this;
}

template<typename T>
inline void my_vector<T>::out() const
{
	for (int l = 0; l < now; l++) {
		int temp = data[l];
		int wei[10];
		int n = 0;
		while (temp) {
			wei[n++] = temp % 10;
			temp /= 10;
		}
		for (int i = 0; i < 7; ++i) {
			int k = 0 , x = n;
			while ((--x) >= 0) {
				for (int j = 0; j < 4; ++j) {
					std::cout << "\033[31;1m" << p[wei[x]][i][j] << "\033[0m";
					//std::cout << "\033[30;4msegment fault !\033[0m";
					//std::cout << p[wei[x]][i][j];
				}
				std::cout << " ";
				k++;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl << std::endl;
	}
}











