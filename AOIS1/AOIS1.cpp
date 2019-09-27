#include <iostream>
#include <vector>
using namespace std;


vector <bool> zero{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
vector <bool> one_addition{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
vector <bool> one{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };
struct float_ {
	vector <bool> mantissa;
	vector <bool> index;
};

const float_ f_pos_x1 = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 } };
const float_ f_neg_x1 = { { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 } };
const float_ f_pos_x2 = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 } };
const float_ f_neg_x2 = { { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 } };

vector<bool> to_pryam(int x) {
	int xm = abs(x);
	vector<bool> result;
	while (xm != 0) {
		if (xm % 2 == 0) {
			result.insert(result.begin(),0);
			xm /= 2;
		}
		if (xm % 2 == 1) {
			result.insert(result.begin(),1);
			xm = (xm - 1) / 2;
		}
	}
	for (int i = 0; result.size() < 16; i++) {
		result.insert(result.begin(), 0);
	}
	if (x < 0) {
		result[0] = 1;
	}
	return result;
}

vector<bool> to_neg(vector<bool> x, int x1) {
	vector<bool> result(x.size());
	if (x1 >= 0) return x;
	if (x1 < 0) {
		for (int i = 0; i < x.size(); i++) {
			result[i]= !x[i];
		}
		result[0] = 1;
	}
	return result;
}

vector<bool> slogenie(vector<bool> x1, vector<bool> x2) {
	vector <bool> res;
	bool trans = false;
	for (size_t i = x1.size(); i > 0; i--)
	{
		if (x1[i - 1] == 0 && x2[i - 1] == 0 && trans == false)
		{
			res.emplace(res.begin(), 0);
			trans = false;
		}
		else if (x1[i - 1] == 0 && x2[i - 1] == 0 && trans == true)
		{
			res.emplace(res.begin(), 1);
			trans = false;
		}
		else if (x1[i - 1] == 1 && x2[i - 1] == 0 && trans == false)
		{
			res.emplace(res.begin(), 1);
			trans = false;
		}
		else if (x1[i - 1] == 1 && x2[i - 1] == 0 && trans == true)
		{
			res.emplace(res.begin(), 0);
			trans = true;
		}
		else if (x1[i - 1] == 0 && x2[i - 1] == 1 && trans == false)
		{
			res.emplace(res.begin(), 1);
			trans = false;
		}
		else if (x1[i - 1] == 0 && x2[i - 1] == 1 && trans == true)
		{
			res.emplace(res.begin(), 0);
			trans = true;
		}
		else if (x1[i - 1] == 1 && x2[i - 1] == 1 && trans == false)
		{
			res.emplace(res.begin(), 0);
			trans = true;
		}
		else if (x1[i - 1] == 1 && x2[i - 1] == 1 && trans == true)
		{
			res.emplace(res.begin(), 1);
			trans = true;
		}
	}
	return res;
}

vector<bool> to_dop(vector<bool> x1, vector<bool> x2, int m) {
	vector<bool> rez;
	if(m >= 0){
		return x1;
	}
	if (m < 0) {
		rez = (slogenie(x1, x2));
		rez[0] = 1;
		return rez;
	}
}

vector<bool> vichit(vector<bool> x1, vector<bool> x2, int t1, int t2) {
	vector<bool> temp1, temp2;
	for (int i = 0; i < 15; i++) {
		temp1.push_back(x1[i]);
		temp2.push_back(x2[i]);
	}
	vector<bool> res(15);
	bool trans = false;
	for (int i = 0; i < 15; i++) {
		if (temp1[i] == 0 && temp2[i] == 0 && trans == 0) {
			res[i] = 0;
			trans = 0;
		}
		if (temp1[i] == 1 && temp2[i] == 0 && trans == 0) {
			res[i] = 1;
			trans = 0;
		}
		if (temp1[i] == 1 && temp2[i] == 1 && trans == 0) {
			res[i] = 0;
			trans = 0;
		}
		if (temp1[i] == 0 && temp2[i] == 0 && trans == 1) {
			res[i] = 1;
			trans = 1;
		}
		if (temp1[i] == 1 && temp2[i] == 0 && trans == 1) {
			res[i] = 0;
			trans = 0;
		}
		if (temp1[i] == 1 && temp2[i] == 1 && trans == 1) {
			res[i] = 0;
			trans = 0;
		}
		if (temp1[i] == 0 && temp2[i] == 1) {
			res[i] = 1;
			trans = 1;
		}
	}
	if (t1 > 0 && t1 > t2) {
		res.insert(res.begin(), 0);
	}
	else {
		res.insert(res.begin(), 1);
	}
	return res;
}

vector<bool> prov(vector<bool> a, vector<bool> b, int x1, int x2) {
	vector<bool> pr;
	if (a[0] == b[0]) {
		if (x1 > 0 && x2 > 0 && x1 > x2) {
			pr = vichit(a, b, x1, x2);
		}
		else if (x1 > 0 && x2 > 0 && x1 < x2) {
			pr = vichit(b, a, x2, x1);
			pr[0] = 0;
 		}
		else if (x1 < 0 && x2 < 0 && (abs(x1) > abs(x2))) {
			a[0] = 0;
			b[0] = 0;
			pr = (vichit(a, b, x1, x2));
			pr[0] = 1;
		}
		else if (x1 < 0 && x2 < 0 && (abs(x1) < abs(x2))) {
			a[0] = 0;
			b[0] = 0;
			pr = vichit(b, a, x2, x1);
			pr[0] = 1;
		}
	}
	else if (a[0] == 0 && b[0] == 0 && x1 < x2) {
		pr = vichit(b, a, x2, x1);
		pr[0] = 1;
	}
	else if (a[0] == 0 && b[0] == 1) {
		b[0] = 0;
		pr = slogenie(a, b);
	}
	else if (a[0] == 1 && b[0] == 0) {
		a[0] = 0;
		pr = slogenie(a, b);
		pr[0] = 1;
	}
	return pr;
}


vector <bool> multiplication(vector <bool> a, vector <bool> b)
{
	vector <bool> res = zero;
	bool flag = false;
	if (a[0] == b[0])
	{
		flag = true;
	}
	if (b[0] == 1)
	{
		b[0] = 0;
	}
	if (b[0] == 1)
	{
		b[0] = 0;
	}
	while (b != zero)
	{
		res = slogenie(a, res);
		b = slogenie(b, one_addition);
	}
	if (flag == true)
	{
		res[0] = 0;
	}
	else
	{
		res[0] = 1;
	}
	return res;
}
vector <bool> from_addition_to_reverse(vector <bool> bin)
{
	if (bin[0] == 1)
	{
		bin = slogenie(bin, one_addition);
		return bin;
	}
	else return bin;
}
vector <bool> from_reverse_to_straight(vector <bool> bin)
{
	if (bin[0] == 1)
	{
		for (int i = 0; i < 16; i++)
		{
			bin[i] = !bin[i];
		}
		bin[0] = 1;
		return bin;
	}
	else return bin;
}
vector <bool> from_straight_to_addition(vector <bool> bin)
{
	for (size_t i = 0; i < bin.size(); i++)
	{
		bin[i] = !bin[i];
	}
	bin[0] = 1;
	bin = slogenie(bin, one);
	return bin;
}
void division(vector <bool> a, vector <bool> b)
{
	vector <bool> res;
	vector <bool> remainder;
	vector <bool> b_plus;
	int off_a = 0;
	int off_b = 0;
	int off = 0;
	bool sign = false;

	if (a[0] == b[0])
	{
		sign = true;
	}

	if (a[0] == 1)
	{
		a = from_reverse_to_straight(from_addition_to_reverse(a));
		a[0] = 0;
	}

	if (b[0] == 1)
	{
		b = from_reverse_to_straight(from_addition_to_reverse(b));
		b[0] = 0;
	}
	b_plus = b;

	do
	{
		off_a++;
	} while (a[off_a] != 1);

	do
	{
		off_b++;
	} while (b[off_b] != 1);

	off = off_b - off_a;
	for (int i = 0; i < off; i++)
	{
		b.push_back(0);
		b.erase(b.begin());
	}
	b[0] = 1;
	b = from_straight_to_addition(b);
	remainder = slogenie(a, b);
	if (remainder[0] == 1)
	{
		res.emplace(res.begin(), 0);
	}
	else
	{
		res.emplace(res.begin(), 1);
	}

	for (int i = 0; i < off; i++)
	{
		b_plus.push_back(0);
		b_plus.erase(b_plus.begin());
		remainder.push_back(0);
		remainder.erase(remainder.begin());

		if (remainder[0] == 1)
		{
			remainder = slogenie(remainder, b_plus);
		}
		else
		{
			remainder = slogenie(remainder, b);
		}

		if (remainder[0] == 1)
		{
			res.push_back(0);
		}
		else
		{
			res.push_back(1);
		}
	}

	if (remainder[0] == 1)
	{
		remainder = slogenie(remainder, b_plus);
	}

	for (int i = 0; i < off; i++)
	{
		remainder.erase(remainder.begin() + 15);
		remainder.emplace(remainder.begin(), 0);
	}

	int sz = res.size();
	for (size_t i = 0; i < 16 - sz; i++)
	{
		res.emplace(res.begin(), 0);
	}

	if (!sign)
	{
		cout << "-";
	}
	for (size_t i = 0; i < res.size(); i++)
	{
		cout << res[i];
	}
	cout << ',';
	for (size_t i = 11; i < remainder.size(); i++)
	{
		cout << remainder[i];
	}
	cout << endl;
}
void float_addition(float_ a, float_ b)
{
	float_ res;
	bool sign = true;
	if (a.mantissa[0] != b.mantissa[0])
	{
		sign = false;
	}
	while (a.index != b.index)
	{
		a.index = slogenie(a.index, one);
		a.mantissa.emplace(a.mantissa.begin(), 0);
		a.mantissa.erase(a.mantissa.begin() + 1);
	}
	res.mantissa = slogenie(a.mantissa, b.mantissa);
	res.index = a.index;

	if (!sign)
		cout << "0,";
	for (size_t i = 0; i < res.mantissa.size(); i++)
	{
		cout << res.mantissa[i];
	}
	cout << "*2^";
	for (size_t i = 0; i < res.index.size(); i++)
	{
		cout << res.index[i];
	}
	cout << endl;
}

void retur(vector<bool> x1) {
	for (int i = 0; i < x1.size(); i++) {
		cout << x1[i];
	}
}
int main()
{
	vector<bool> x1, x2, bx1, bx2, dx1, dx2, x3, x4, bx3, bx4, dx3, dx4;
	int ix1 = 10, ix2 = 25, x12 = 35, x1_2 = -15, x2_1 = 15, x_1_2 = -35, mx1 = -10, mx2 = -25;
	int x13 =250, x1_3 = -250, x_13 = -250;
	x1 = to_pryam(ix1);
	x2 = to_pryam(ix2);
	x3 = to_pryam(mx1);
	x4 = to_pryam(mx2);
	bx1 = (to_neg(x1, ix1));
	bx2 = (to_neg(x2, ix2));
	bx3 = to_neg(x3, mx1);
	bx4 = to_neg(x4, mx2);
	vector<bool> one = to_pryam(1);
	dx1 = to_dop(bx1, one, ix1);
	dx2 = to_dop(bx2, one, ix2);
	dx3 = to_dop(bx3, one, mx1);
	dx4 = to_dop(bx4, one, mx2);
	cout << "////////X1 = 10////////\n";
	cout << "in straight: ";
	retur(x1);
	cout << "\nin reverse: ";
	retur(bx1);
	cout << "\nin addition: ";
	retur(dx1);

	cout << "\n////////X2 = 25////////\n";
	cout << "in straight: ";
	retur(x2);
	cout << "\nin reverse: ";
	retur(bx2);
	cout << "\nin addition: ";
	retur(dx2);

	cout << "\n////////-X1 = -10////////\n";
	cout << "in straight: ";
	retur(x3);
	cout << "\nin reverse: ";
	retur(bx3);
	cout << "\nin addition: ";
	retur(dx3);

	cout << "\n////////-X2 = -25////////\n";
	cout << "in straight: ";
	retur(x4);
	cout << "\nin reverse: ";
	retur(bx4);
	cout << "\nin addition: ";
	retur(dx4);
	
	vector<bool> sl, bsl, dsl;
	sl = slogenie(x1, x2);
	bsl = to_neg(sl, x12);
	dsl = to_dop(bsl, one, x12);
	cout << "\n////////X1+X2 = 35/////////\n";
	cout << "in straight: ";
	retur(sl);
	cout << "\nin reverse: ";
	retur(bsl);
	cout << "\nin addition: ";
	retur(dsl);
	
	sl = to_pryam(x2_1);
	bsl = to_neg(sl, x2_1);
	dsl = to_dop(bsl, one, x2_1);

	cout << "\n/////////-X1+X2 = 15//////////\n";
	cout << "in straight: ";
	retur(sl);
	cout << "\nin reverse: ";
	retur(bsl);
	cout << "\nin addition: ";
	retur(dsl);

	sl = to_pryam(x1_2);
	bsl = to_neg(sl, x1_2);
	dsl = to_dop(bsl, one, x1_2);

	cout << "\n/////////X1-X2 = -15//////////\n";
	cout << "in straight: ";
	retur(sl);
	cout << "\nin reverse: ";
	retur(bsl);
	cout << "\nin addition: ";
	retur(dsl);

	sl = to_pryam(x_1_2);
	bsl = to_neg(sl, x_1_2);
	dsl = to_dop(bsl, one, x_1_2);

	cout << "\n/////////-X1-X2 = -35//////////\n";
	cout << "in straight: ";
	retur(sl);
	cout << "\nin reverse: ";
	retur(bsl);
	cout << "\nin addition: ";
	retur(dsl);
	
	vector<bool> mp, bmp, dmp;
	mp = to_pryam(x13);
	bmp = to_neg(sl, x13);
	dmp = to_dop(bsl, one, x13);

	cout << "\n/////////X1*X2 = 250//////////\n";
	cout << "in straight: ";
	retur(mp);
	cout << "\nin reverse: ";
	retur(bmp);
	cout << "\nin addition: ";
	retur(dmp);

	mp = to_pryam(x_13);
	bmp = to_neg(sl, x_13);
	dmp = to_dop(bsl, one, x_13);

	cout << "\n/////////-X1*X2 = -250//////////\n";
	cout << "in straight: ";
	retur(mp);
	cout << "\nin reverse: ";
	retur(bmp);
	cout << "\nin addition: ";
	retur(dmp);

	mp = to_pryam(x1_3);
	bmp = to_neg(sl, x1_3);
	dmp = to_dop(bsl, one, x1_3);

	cout << "\n/////////X1*(-X2) = -250//////////\n";
	cout << "in straight: ";
	retur(mp);
	cout << "\nin reverse: ";
	retur(bmp);
	cout << "\nin addition: ";
	retur(dmp);

	cout << "\n/////////X1/X2//////////\n";
	division(to_pryam(ix1), to_pryam(ix2));

	cout << "\n/////////-X1/X2//////////\n";
	division(to_dop(to_neg(to_pryam(mx1), mx1), one, mx1), to_pryam(ix2));

	cout << "\n/////////-X1/-X2//////////\n";
	division(to_dop(to_neg(to_pryam(mx1), mx1), one, mx1), to_dop(to_neg(to_pryam(mx2), mx2), one, mx2));

	cout << "\n/////////X1/-X2//////////\n";
	division(to_pryam(ix1), to_dop(to_neg(to_pryam(mx2), mx2), one, mx2));

	cout << "\n/////////X1_float+X2_float//////////\n";
	float_addition(f_pos_x1, f_pos_x2);
	system("pause");
}
