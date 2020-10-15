#define _CRT_SECURE_NO_DEPRECATE
/*
Meno a priezvisko: Martin Zofcik 98034

POKYNY:
(1)  Subor premenujte na Priezvisko_Meno_ID_du06.cpp (pouzite vase udaje bez diakritiky).
(2)  Implementujte funkcie tak, aby splnali popis pri ich deklaraciach.
(3)  Cela implementacia musi byt v tomto jednom subore.
(4)  Odovzdajte len tento (spravne premenovany) zdrojovy subor.
(5)  Program musi byt kompilovatelny.
(6)  Globalne a staticke premenne su zakazane.
(7)  V ziadnom pripade nemente deklaracie funkcii, ktore mate za ulohu naprogramovat
	 (nemente nazvy, navratove hodnoty ani typ a pocet parametrov v zadanych funkciach).
	 Nemente implementacie zadanych datovych typov, ani implementacie hotovych pomocnych funkcii
	 (ak nie je v zadani ulohy uvedene inak).
(8)  V pripade potreby mozete kod doplnit o dalsie pomocne funkcie alebo struktury.
(9)  Vase riesenie otestujte (vo funkcii 'main' a pomocou doplnenych pomocnych funkcii alebo struktur).
	 Testovaci kod ale nebude hodnoteny.
(10) Funkcia 'main' musi byt v zdrojovom kode posledna.
*/

#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

//-------------------------------------------------------------------------------------------------
// ULOHA (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
	Do deklaracie funkcie doplnte implicitne hodnoty parametrov.
	Pre parameter 'a' nech je implicitna hodnota 10,
	pre parameter 'b' nech je implicitna hodnota 20.
*/
int sucet(int a = 10, int b = 20) {
	return a + b;
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.9 boda)
//-------------------------------------------------------------------------------------------------
/*
	Trieda 'String' reprezentuje textovy retazec. Doplnte jej implementaciu podla zadania nizsie.

	Trieda implementuje textovy retazec, polom prvkov typu 'char', zakoncenym hodnotou '\0' (ako v jazyku C).
	Adresa tohoto pola je ulozena v atribute 'data'.
	Atribut 'data' musi byt sukromny (v casti 'private').
	Ak do implementacie triedy budete pridavat dalsie atributy, tak atribut 'data' musi zostat ako prvy atribut
	(pridanie dalsich atributov nie je nutne).

	Vytvorte verejne (v casti public) konstruktory, destruktory a metody (kazda poduloha je za 0.1 boda):

	a)  Vytvorte konstruktor bez parametrov.
		Tento konstruktor vytvori objekt reprezentujuci prazdny textovy retazec.

	b)  Vytvorte konstruktor s parametrom typu 'const char *'.
		Tento konstruktor vytvori objekt reprezentujuci textovy retazec, ktory je kopiou vstupneho parametra.

	c)  Vytvorte kopirovaci konstruktor. Tento konstruktor vytvori hlboku kopiu.

	d)  Vytvorte metodu 'size_t getLength() const', ktora vrati pocet znakov v textovom retazci (bez '\0').

	e)  Vytvorte metodu 'char getChar(const size_t index) const'.
		Vstupny parameter je indexom znaku v textovom retazci (prvy znak je na pozicii s indexom nula).
		Metoda vratich znak, ktory sa nachadza na mieste urcenom indexom.
		Ak je 'index' mimo rozsahu, alebo textovy retazec neobsahuje ziadne znaky, tak metoda vrati '\0'.

	f)  Vytvorte metodu 'const char * toCString() const'.
		Metoda vrati smernik na C-ckovsku reprezentaciu textoveho retazca.
		Implementacia je jednoducha, metoda vrati adresu v atribute 'data' (kopiu adresy).
		Poznamka: Kedze (konstantny) typ navratvej hodnoty zabranuje zmene obsahu textoveho retazca, nevytvarajte kopiu textu.

	g)  Vytvorte metodu 'void set(const char *text)',
		ktora nastavi novu hodnotu textoveho retazca podla vstupneho parametra.
		Nezabudnite dealokovat nepotrebnu pamat.

	h)  Vytvorte metodu 'void append(const char *text)', ktora prida na koniec 'text', ktory je vstupnym parametrom.
		Nezabudnite dealokovat nepotrebnu pamat.

	i)  Vytvorte destruktor, ktory v pripade potreby dealokuje pamat.

	Pre alokaciu a dealokaciu poli pouzivajte new[] a delete[].

	Funkcia 'basicTestString' je urcena na test spravnej deklaracie konstruktorov, metod a destruktora.
	Postupne v nej odkomentuj jednotlive riadky. Tieto musia byt po dokonceni vypracovania kompilovatelne.
	Funkcia testuje spravnost funkcnosti len ciastocne. Vytvorte dalsie testy pre overenenie funkcnosti.
*/

class String { // Prve tri riadky deklaracie triedy musia zostat nezmenene
	private:
		char* data; // obsah textoveho retazca (ak pridate dalsie atributy, tak tento musi zostat prvym atributom)
	
	public:
		// a)
		String() {
			data = new char[1];
			data[0] = '\0';
		};

		// b)
		String(const char* text) {
			if (text) {
				data = new char[strlen(text) + 1];
				strcpy(data, text);
			}
			else {
				data = new char[1];
				data[0] = '\0';
			}
		}

		// c)
		String(const String &original) {
			data = new char[original.getLength() + 1];
			strcpy(data, original.data);
		}

		// d)
		size_t getLength() const {
			return strlen(data);
		}

		// e)
		char getChar(const size_t index) const {
			if (index > getLength()) {
				return '\0';
			}
			else return data[index];
		}

		// f)
		const char* toCString() const {
			return data;
		}

		// g)
		void set(const char* text) {
			delete[] data;
			data = new char[strlen(text) + 1];
			strcpy(data, text);
		}

		// h)
		void append(const char* text) {
			char *newData = new char [getLength() + strlen(text) + 1];
			strcpy(newData, data);
			strcpy(newData, text);
			delete[] data;
			data = newData;
		}

		// i)
		~String() {
			delete[] data;
		}
};

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

void basicTestString() {
	// a)
	String str1;

	//b)
	String str2("hello world");

	// c)
	String str3(str2);

	// d)
	size_t length1 = str1.getLength();
	assert(length1 == 0);
	size_t length2 = str2.getLength();
	assert(length2 == 11);

	// e)
	char letter1 = str1.getChar(0);
	assert(letter1 == '\0');
	char letter2 = str2.getChar(0);
	assert(letter2 == 'h');
	char letter3 = str2.getChar(1000);
	assert(letter3 == '\0');

	// f)
	const char *cstr1 = str1.toCString();
	assert(cstr1[0] == '\0');
	const char *cstr2 = str2.toCString();
	assert(std::strcmp(cstr2, "hello world") == 0);

	// g)
	str2.set("hello world again");
	assert(std::strcmp(str2.toCString(), "hello world again") == 0);

	// h)
	//str2.append("dalsi text");///jebe tomu
	//assert(std::strcmp(str2.toCString(), "HELLO WORLD AGAINdalsi text") == 0);

	assert(std::strcmp(str3.toCString(), "hello world") == 0);
}


int main() {

	basicTestString();
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Tema: Triedy, objekty, konstruktor, destruktor
// Autor: Pavol Marak

// STRUCNY POPIS:
//
// V tejto ukazke su naprogramovane dve triedy:
//
//    Trieda 'Movie'
//    
//    Reprezentuje film v databaze filmov. 
//
//    Jej atributmi su:
//       * nazov filmu 'title'
//       * rok vydania 'year'
//       * hodnotenie filmu 'rating' 
//
//    Jej metodami su:
//       * konstruktory (default, parametricky a kopirovaci)
//       * destruktor
//       * nastavovacie metody, tzv. setters
//       * metody na vratenie atributov, tzv. getters
//       * metoda 'print' na vypis informacii o filme
//
// -----------------------------------------------------------------
//
//    Trieda 'MovieDB'
//
//    Reprezentuje databazu filmov a k nej asociovane operacie.
//
//    Jej atributmi su:
//       * pole filmov 'db' (obsahuje objekty typu 'Movie')
//       * aktualny pocet filmov v databaze 'count'
//
//    Jej metodami su:
//       * default konstruktor
//       * metoda 'add' na pridanie filmu do databazy 
//       * metoda 'search' na vyhladanie filmu v databaze podla klucoveho slova 
//       * metoda 'print' na vypis databazy filmov


#define _CRT_SECURE_NO_WARNINGS
#define DB_COUNT 5

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>

//using namespace std;

// definicia triedy 'Movie'
class Movie {
	char* title; // nazov filmu
	int year; // rok vydania filmu
	int rating; // percentualne hodnotenie filmu 0 az 100 %

public:
	// default konstruktor
	Movie() : title(nullptr), year(-1), rating(0) {

	}

	// parametricky konstruktor
	Movie(const char* title, int year, int rating) {
		this->title = nullptr;
		if (title) {
			this->title = new char[strlen(title) + 1];
			strcpy(this->title, title);
		}
		this->year = year;
		this->rating = rating;
	}

	// copy konstruktor - hlboka kopia objektu 'other'
	Movie(const Movie& other) {
		this->title = nullptr;
		if (other.title) {
			this->title = new char[strlen(other.title) + 1];
			strcpy(this->title, other.title);
		}
		this->year = other.year;
		this->rating = other.rating;
	}

	// destruktor
	~Movie() {
		if (this->title) {
			delete[] this->title;
		}
	}

	// set metoda pre atribut 'title'
	void setTitle(const char* title) {
		// ak ma film existujuci nazov, dealokujeme ho
		if (this->title) {
			delete[] this->title;
		}
		this->title = nullptr;
		if (title) {
			this->title = new char[strlen(title) + 1];
			strcpy(this->title, title);
		}
	}

	// set metoda pre atribut 'year'
	void setYear(const int year) {
		this->year = year;
	}

	// set metoda pre atribut 'rating'
	void setRating(const int rating) {
		this->rating = rating;
	}

	// get metoda pre atribut 'title'
	const char* getTitle() const {
		return this->title; // vrati sa len smernik, nie hlboka kopia
	}

	// get metoda pre atribut 'year'
	int getYear() const {
		return this->year;
	}

	// get metoda pre atribut 'rating'
	int getRating() const {
		return this->rating;
	}

	// metoda na vytlacenie informacii o filme do konzoly
	void print() const {
		cout << setw(25) << ((this->title) ? this->title : "---");
		cout << setw(7) << this->year;
		cout << setw(5) << this->rating << " %";
		cout << endl;
	}
};

// definicia triedy 'MovieDB'
class MovieDB {
	Movie db[DB_COUNT]; // pole filmov, t.j. databaza
	int count; // aktualny pocet filmov v databaze
public:
	// default konstruktor
	MovieDB() : count(0) {

	}

	// metoda na pridavanie filmu
	void add(const Movie& movie) {
		if (this->count >= 0 && this->count < DB_COUNT) {
			this->db[this->count].setRating(movie.getRating());
			this->db[this->count].setYear(movie.getYear());
			this->db[this->count++].setTitle(movie.getTitle());
		}
	}
	// metoda na vyhladavanie filmu
	const Movie* search(const char* keyword) const {
		for (int i = 0; i < this->count; i++) {
			if (strstr(this->db[i].getTitle(), keyword)) {
				return &this->db[i];
			}
		}
		return nullptr;
	}

	// metoda na vypis databazy filmov do konzoly
	void print() const {
		cout << endl << setw(30) << "Movie DB" << endl;
		cout << setw(40) << "---------------------------------" << endl;
		for (int i = 0; i < this->count; i++) {
			this->db[i].print();
		}
		cout << endl;
	}
};

// funkcia na testovanie prace s triedou 'Movie'
void test_movie() {
	// 1. Test default konstruktora
	Movie m1;

	// 2. Test parametrickeho konstruktora
	Movie m2(" Terminator: Dark Fate", 2019, 72);

	// 3. Test kopirovacieho konstruktora
	Movie example("Joker", 2019, 90);
	Movie m3(example); // tu sa vola kopirovaci konstruktor

	// 4. Test metod na nastavenie atributov (setters)
	example.setRating(85);
	example.setTitle("Titanic");
	example.setYear(1997);

	// 5. Test metod na vratenie atributov (getters)
	int movie_rating = example.getRating();
	const char* movie_title = example.getTitle();
	int movie_year = example.getYear();

	// 6. Test metody na vypis filmu
	example.print();

	// 7. Desktruktory objektov sa budu volat po ukonceni funkcie v obratenom poradi:
	//    m3 -> example -> m2 -> m1
	// Mozete si to otestovat bud v Debug rezime alebo pridanim vypisov do destruktora.
}

// funkcia na testovanie prace s triedou 'MovieDB'
void test_movie_db() {
	// 1. Test default konstruktora
	MovieDB db;

	// 2. Test metody 'add' na pridanie filmu do databazy
	const char* movie_titles[DB_COUNT] = {
		"Harry Potter",
		"Gladiator",
		"Godzilla",
		"Lion King",
		"Finding Nemo"
	};

	for (int i = 0; i < DB_COUNT; i++) {
		db.add(Movie(movie_titles[i], 2000 + i, i * 20));
	}

	// 3. Test metody 'print' na vypis databazy filmov
	db.print();

	// 4. Interaktivny test metody 'search' na vyhladanie filmu v databaze
	char keyword[100];
	cout << "Hladaj film podla klucoveho slova: ";
	cin >> keyword;
	const Movie* result = db.search(keyword);
	if (result) {
		cout << endl;
		result->print();
	}
	else {
		cout << endl << "Nic sa nenaslo" << endl;
	}
}

int main() {
	test_movie();
	test_movie_db();
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Tema: Trieda string
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

//using namespace std;

// ODPORUCANY ZDROJ: 
// http://www.cplusplus.com/reference/string/string/?kw=string
// https://en.cppreference.com/w/cpp/string/basic_string

// POZNAMKA: tento program si otestujte v Debug rezime
// pretoze nie vsetky casti kodu su vizualizovane vypisom
// do konzoly

int main() {
	// klasicky C retazec
	const char c_string[10] = "Ahoj";

	// Trieda 'std::string' zo standardnej kniznice C++

	// 1. konstruktory stringu
	string a1; // default konstruktor
	string a2("abcdefgh"); // z C retazca
	string a3(a2); // copy konstruktor
	string a4(a3, 1, 2); // substring konstruktor
	string a5(10, 'x'); // fill konstruktor

	// 2. kopirovanie stringov (hlboka kopia)
	// v jazyku C bolo treba pouzit funkciu strcpy()
	string b1("nieco");
	string b2;
	b2 = b1;
	// porovnanie adries stringov
	cout << (void*)b1.data() << endl << (void*)b2.data() << endl;

	// 3. operatory

	// operator +
	string c1 = "ABC";
	c1 = c1 + "D";
	cout << c1 << endl;

	// operator +=
	string c2 = "Ako sa";
	c2 += " mas?";
	cout << c2 << endl;

	// operator ==
	string c3 = "A";
	string c4 = "a";
	cout << (c3 == c4 ? "rovnake" : "rozne") << " stringy" << endl;

	// 4. velkost retazca, pristup k znakom
	string d1 = "dlhy retazec";
	cout << "Dlzka retazca: " << d1.length() << endl;
	// metoda at() kontroluje, ci pristupujeme k platnemu znaku
	cout << d1[3] << " = " << d1.at(3) << endl;

	// 5. insert, erase, clear
	string e1 = "Bslava";
	e1.insert(1, "rati");
	cout << e1 << endl;

	string e2 = "Ahqqqoj";
	e2.erase(2, 3);
	cout << e2 << endl;

	string e3 = "aaaaaa";
	e3.clear();
	cout << e3 << endl;

	// 6. podretazec, vyhladavanie
	string f1 = "Ahoj mama";
	cout << f1.substr(5) << endl;

	string f2 = "A very long text";
	cout << (f2.find("very") != string::npos ? "naslo sa" : "nenaslo sa") << endl;

	// 7. konverzia do C retazca
	string g1 = "C retazec";
	const char* text = g1.c_str();
	cout << text << endl;

	// 8. globalna funkcia 'to_string'
	string h1;
	h1 = to_string(1.2345);
	cout << h1 << endl;

	// 9. globalna funkcia 'getline'
	string i1;
	cout << "Zadajte text: ";
	// funkcia nacita text az po prvy vyskyt znaku '.'
	getline(cin, i1, '.');
	cout << "Nacitany text: " << i1 << endl;

	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Tema: Vynimky

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdexcept>
//using namespace std;


// Vlastna vynimkova trieda na podrobnejsiu reprezentaciu 
// vlastnej vynimocnej udalosti pocas behu programu
class CustomException {
private:
	string message;
public:
	// parametricky konstruktor
	CustomException(const string& message)
		: message(message) {
	}
	// metoda na vypis informacii o vynimke
	const string& what() const {
		return message;
	}
};

// POZNAMKA: tento program si otestujte v Debug rezime
// pretoze nie vsetky casti kodu su vizualizovane vypisom
// do konzoly

int main() {
	int num;

	try {
		cout << "Zadaj nezaporne cislo: ";
		cin >> num; // pouzivatel zada cislo z klavesnice
		if (num < 0) {
			throw string{ "bolo zadane zaporne cislo" }; // vyhodi sa vynimka typu 'string'
		}
		string s{ "abc" };
		//s.at(100); // ked odkomentujeme, vyhodi sa standardna vynimka typu 'out_of_range'
		throw CustomException{ "vlastny vynimkovy objekt" }; // vyhodime vynimku typu 'CustomException'
	}
	// exception handler pre vynimku typu 'string'
	catch (const string& e) {
		cout << "Vynimka: " << e << endl;
	}
	// exception handler pre vynimku typu 'out_of_range'
	catch (const out_of_range& e) {
		cout << "Vynimka: " << e.what() << endl;
	}
	// exception handler pre vynimku typu 'CustomException'
	catch (const CustomException& e) {
		cout << "Vynimka: " << e.what() << endl;
	}

	cout << endl << "Program pokracuje po try-catch bloku..." << endl;
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Tema: STL map

// Poznamky:
//
// Kontajner 'map' predstavuje usporiadanu kolekciu
// 'key-value' parov. Prvky su usporiadane podla klucov.
// Kluce su nemenne a unikatne. Do mapy nie je mozne
// pridat prvky s rovnakym klucom. Prvky mapy musia
// byt porovnatelne, teda musi byt jasne, za akych
// podmienok je prvok vlavo mensi ako prvok vpravo.
// Pre zakladne datove typy je porovnatelnost automaticka
// avsak pre pouzivatelske typy musime dodat vlastny
// porovnavaci funktor, funkciu alebo lambdu.
// Ked iterujeme cez mapu, prvky spristupnujeme implicitne
// v usporiadanom poradi.
//
// Vyhody:
// * vyhladavanie prvku v logaritmickom case

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
using namespace std;

// testovacia funkcia pre STL map
void test_stl_map() {
	// konstrukcia a inicializacia mapy
	map<string, string> slovnik{
		{"nadej","hope"},
		{"pribeh","story"},
		{"hra", "game"},
		{"poklad","treasure"},
		{"clovek","man"},
		{"noc","night"},
		{"film","movie"}
	};

	// vypis mapy (cez iterator)
	cout << "Vypis mapy (cez iterator):" << endl;
	for (auto it = slovnik.begin(); it != slovnik.end(); it++) {
		cout << " " << (*it).first << " -> " << (*it).second << endl;
	}
	cout << endl;

	// pridavanie prvkov do mapy
	auto p1 = slovnik.insert({ "film","movie" }); // pokus o pridanie duplikatu
	cout << "Pridavam {\"film\",\"movie\"} ... ";
	if (!p1.second) {
		cout << " NEPRIDANE (duplikat)";
	}
	else {
		cout << " PRIDANE";
	}
	cout << endl << endl;

	auto p2 = slovnik.insert({ "vietor","wind" }); // pridanie noveho prvku
	cout << "Pridavam {\"vietor\",\"wind\"} ... ";
	if (!p2.second) {
		cout << " NEPRIDANE (duplikat)";
	}
	else {
		cout << " PRIDANE";
	}
	cout << endl << endl;

	// vymazavanie z mapy
	size_t n = slovnik.erase("poklad");
	cout << "Prvok s klucom \"poklad\" " << (n ? "bol" : "nebol") << " vymazany" << endl << endl;

	// pristup k namapovanej hodnote
	string r1 = slovnik["clovek"];

	// rychle pridanie do mapy pomocou []
	slovnik["duha"] = "rainbow";

	// aktualizacia namapovanej hodnoty pomocou []
	slovnik["pribeh"] = "tale";

	// vyhladanie prvku
	auto r2 = slovnik.find("nadej");
	cout << "Prvok s klucom \"nadej\" " << (r2 != slovnik.end() ? "bol" : "nebol") << " najdeny" << endl << endl;

	// vymazanie obsahu mapy
	slovnik.clear();
}

int main() {
	cout << endl << "STL map" << endl;
	cout << "........................." << endl << endl;
	test_stl_map();
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

cout << "Vypis kontajneru 'vector' pomocou iteratora:" << endl;
vector<int>::iterator vector_it;
for (vector_it = cisla.begin(); vector_it != cisla.end(); vector_it++) {
cout << " " << *vector_it << endl;

cout << endl << "Vypis kontajneru 'map' pomocou iteratora:" << endl;
map<int, string>::iterator map_it;
for (map_it = mapa.begin(); map_it != mapa.end(); map_it++) {
	cout << " " << (*map_it).first << " -> " << (*map_it).second << endl;
}

cout << endl << "Vypis kontajneru 'list' pomocou reverzneho iteratora:" << endl;
list<string>::reverse_iterator list_rit;
for (list_rit = mena.rbegin(); list_rit != mena.rend(); list_rit++) {
	cout << " " << *list_rit << endl;
}

// range-based for cyklus na prechod vektorom (by value)
cout << endl << endl << "Range-based for cyklus na prechod vektorom (by value):" << endl;
for (int i : v) {
	cout << " " << i;

// range-based for cyklus na prechod mapou (by value)
cout << endl << endl << "Range-based for cyklus na prechod mapou (by value):" << endl;
for (pair<const string, string> p : m) {
	cout << " (" << p.first << "," << p.second << ")";
	// premennu 'p' mozeme zmenit, ale v mape sa ziadna hodnota nezmeni,
	// nakolko 'p' je kopia prvku kontajnera
}
