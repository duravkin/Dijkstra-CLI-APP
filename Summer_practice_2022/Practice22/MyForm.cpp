#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Practice22::MyForm form;
	Application::Run(% form);
}
#include <iostream>
#include <vector>

struct Vector2DSTR {
	int X,
		Y;
};
Vector2DSTR mousePosition;

struct RoadSTR {
	int A,
		B,
		LEN;
};

// Далее объявятся глобальные переменные для нашего проекта:
std::vector <Vector2DSTR> Tops; // Вектор для хранения координат вершин.
int SizePen = 20;
bool ButtonCreateTop = false,
	ButtonDeleteTop = false,
	ButtonMoveTop = false,
	ButtonCreateRoad = false,
	ButtonSearchRoad = false;

bool InsideTheFrame = false;

int SelectIndex = -1;
bool SelectMoveTop = false;
Vector2DSTR TempMoveTop;


std::vector <RoadSTR> Roads; // Вектор для хранения индексов вершин, которые связывает дуга, и длин этих дуг.
bool SelectRoad = false;
RoadSTR TempRoad;

RoadSTR ShortRoad;
std::vector <int> ShortWay; // Вектор хранения короткого пути.
bool SelectSearchTop = false;

// Функции для работы программы:
// Поиск индекса вершины.
int Search() {
	int MinIndex = -1;
	Vector2DSTR Top;
	Top.X = SizePen;
	Top.Y = SizePen;
	for (int i = 0; i < Tops.size(); i++) {
		if (abs(mousePosition.X - Tops[i].X) < Top.X && abs(mousePosition.Y - Tops[i].Y) < Top.Y) {
			MinIndex = i;
			Top.X = abs(mousePosition.X - Tops[i].X);
			Top.Y = abs(mousePosition.Y - Tops[i].Y);
		}
	}
	return MinIndex;
}

// Алгоритм Дейкстры.
void Deikstra() {
	std::vector <int> Wt; // Верктор хранения веса до вершины.
	std::vector <bool> TopsCheck; // Вектор посещенности вершины.
	ShortWay.erase(ShortWay.begin(), ShortWay.end()); // Очистим вектор пути.
	const int INF = 10000000000;
	for (int n = 0; n < Tops.size(); n++) { // Создадим переменные веса вершины и идентификатор посещенности.
		Wt.push_back(INF);
		TopsCheck.push_back(false);
	}
	Wt[ShortRoad.A] = 0;
	int MinN = ShortRoad.A;
	for (int i = 0; i < Tops.size(); i++) {
		for (int j = 0; j < Roads.size(); j++)
			if (MinN == Roads[j].A && TopsCheck[MinN] == false) 
				if (Wt[Roads[j].B] > Wt[Roads[j].A] + Roads[j].LEN) 
					Wt[Roads[j].B] = Wt[Roads[j].A] + Roads[j].LEN; // Узнаём минимальное значение между текущим весом и новым возможным.
		TopsCheck[MinN] = true;
		int MinWt = INF;
		for (int j = 0; j < Tops.size(); j++) {
			if (TopsCheck[j] == false) if (MinWt > Wt[j]) { // Сохраняем минимальное значение из пройденных.
				MinWt = Wt[j];
				MinN = j;
			}
		}
	}
	if (Wt[ShortRoad.B] != INF) {
		ShortRoad.LEN = Wt[ShortRoad.B];

		// Восстановим путь для отрисовки пути на экране.
		int TopWay = ShortRoad.B;
		MinN = TopWay;
		int MinWt = INF;
		ShortWay.push_back(TopWay);
		for (int i = 0; i < Wt.size(); i++) {
			bool HaveTop = false;
			for (int j = 0; j < Roads.size(); j++) {
				if (TopWay == Roads[j].B && MinWt >= Wt[Roads[j].A] + Roads[j].LEN) {
					MinWt = Wt[Roads[j].A] + Roads[j].LEN;
					MinN = Roads[j].A;
					HaveTop = true;
				}
			}
			if (HaveTop == true && TopWay != MinN) ShortWay.push_back(MinN);
			TopWay = MinN;
		}
	}
	else ShortRoad.LEN = -2;
}


// Инициализация некоторых значений при загрузке формы.
System::Void Practice22::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	PenForTops = gcnew Pen(Color::Blue, SizePen);
	PenForRoads = gcnew Pen(Color::Yellow, SizePen * 0.15);
	font = gcnew Drawing::Font("Microsoft Sant Serif", 8);
	brush = gcnew SolidBrush(Color::Black);
}

// Отрисовщик на холсте.
System::Void Practice22::MyForm::PaperBox_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	// Перепроверить и исправить оформление.
	if (ButtonCreateRoad && SelectRoad) { // Визуализация дороги от выбранной вершины до курсора.
		if (InsideTheFrame) e->Graphics->DrawLine(PenForRoads, Tops[TempRoad.A].X, Tops[TempRoad.A].Y, mousePosition.X, mousePosition.Y);
	}

	for (int i = 0; i < Roads.size(); i++) { // Отрисовка всех дорог из памяти.
		double d = sqrt(pow((Tops[Roads[i].A].X - Tops[Roads[i].B].X), 2) + pow((Tops[Roads[i].A].Y - Tops[Roads[i].B].Y), 2)); // Находим длину данного пути.
		double n1 = log(1 / (1 - ((d - SizePen * 2) / d))) / log(2); // Процентное соотношение до точки начала отображения стрелки.
		double n2 = log(1 / (1 - ((d - SizePen) / d))) / log(2); // Процентное осотношение до точки конца стрелки.

		// Прямая до начала отрисовки стрелочки.
		e->Graphics->DrawLine(PenForRoads, Tops[Roads[i].A].X, Tops[Roads[i].A].Y, (Tops[Roads[i].A].X + (pow(2, n1) - 1) * Tops[Roads[i].B].X) / pow(2,n1), (Tops[Roads[i].A].Y + (pow(2, n1) - 1) * Tops[Roads[i].B].Y) / pow(2, n1));
		e->Graphics->DrawLine(gcnew Pen(Color::Yellow, SizePen * 0.3), (Tops[Roads[i].A].X + (pow(2, n1) - 1) * Tops[Roads[i].B].X) / pow(2, n1), (Tops[Roads[i].A].Y + (pow(2, n1) - 1) * Tops[Roads[i].B].Y) / pow(2, n1), Tops[Roads[i].B].X, Tops[Roads[i].B].Y);
		
		// Текст длины дуги посередине между вершинами.
		if (Roads[i].LEN != -1) e->Graphics->DrawString(Convert::ToString(Roads[i].LEN), font, brush, (Tops[Roads[i].A].X + Tops[Roads[i].B].X) / 2, (Tops[Roads[i].A].Y + Tops[Roads[i].B].Y) / 2);
	}

	// Отрисовка кратчайшего пути.
	if (ButtonSearchRoad && ShortRoad.LEN > 0 && ShortWay.size() > 1) for (int i = ShortWay.size() - 1; i > 0; i--) {
		int A = ShortWay[i], B = ShortWay[i - 1];
		double d = sqrt(pow((Tops[A].X - Tops[B].X), 2) + pow((Tops[A].Y - Tops[B].Y), 2)); // Находим длину данного пути.
		double n1 = log(1 / (1 - ((d - SizePen * 2) / d))) / log(2); // Процентное соотношение до точки начала отображения стрелки.
		double n2 = log(1 / (1 - ((d - SizePen) / d))) / log(2); // Процентное осотношение до точки конца стрелки.

		// Прямая до начала отрисовки стрелочки.
		e->Graphics->DrawLine(gcnew Pen(Color::Green, SizePen * 0.15), Tops[A].X, Tops[A].Y, (Tops[A].X + (pow(2, n1) - 1) * Tops[B].X) / pow(2, n1), (Tops[A].Y + (pow(2, n1) - 1) * Tops[B].Y) / pow(2, n1));
		e->Graphics->DrawLine(gcnew Pen(Color::Green, SizePen * 0.3), (Tops[A].X + (pow(2, n1) - 1) * Tops[B].X) / pow(2, n1), (Tops[A].Y + (pow(2, n1) - 1) * Tops[B].Y) / pow(2, n1), Tops[B].X, Tops[B].Y);
	}

	for (int i = 0; i < Tops.size(); i++) { // Отрисовка всех вершин из памяти.
		e->Graphics->DrawEllipse(gcnew Pen(Color::Black, SizePen * 1.1), Tops[i].X - SizePen / 2, Tops[i].Y - SizePen / 2, SizePen, SizePen);
		e->Graphics->DrawEllipse(PenForTops, Tops[i].X - SizePen / 2, Tops[i].Y - SizePen / 2, SizePen, SizePen);
		if (ButtonSearchRoad && SelectIndex == i && SelectSearchTop || ButtonCreateRoad && SelectIndex == i && SelectRoad)
			e->Graphics->DrawString(Convert::ToString(i + 1), font, gcnew SolidBrush(Color::Yellow), Tops[i].X - 4, Tops[i].Y - 4);
		else
			e->Graphics->DrawString(Convert::ToString(i + 1), font, brush, Tops[i].X - 4, Tops[i].Y - 4);
	}

	if (ButtonCreateTop && InsideTheFrame) { // Отрисовка вершины под курсором во время рисования.
		e->Graphics->DrawEllipse(PenForTops, mousePosition.X - SizePen / 2, mousePosition.Y - SizePen / 2, SizePen, SizePen);
	}
}

// Обработка события - Создать вершину.
System::Void Practice22::MyForm::CreateTop_Click(System::Object^ sender, System::EventArgs^ e) {
	if (ButtonCreateTop == false) {
		ButtonCreateTop = true; CreateTop->BackColor = Color::Blue;

		// Отмена прочих активных кнопок:
		ButtonDeleteTop = false; DeleteTop->BackColor = Color::Gainsboro;
		ButtonMoveTop = false; MoveTop->BackColor = Color::Gainsboro;
		ButtonCreateRoad = false; CreateRoad->BackColor = Color::Gainsboro;
		ButtonSearchRoad = false; SearchRoad->BackColor = Color::Gainsboro;
	}
	else {
		ButtonCreateTop = false; CreateTop->BackColor = Color::Gainsboro;
	}
	PaperBox->Invalidate(); // Перерисовка.
}

// Обработка события - Удалить вершину.
System::Void Practice22::MyForm::DeleteTop_Click(System::Object^ sender, System::EventArgs^ e) {
	if (ButtonDeleteTop == false) {
		ButtonDeleteTop = true; DeleteTop->BackColor = Color::Blue;

		// Отмена прочих активных кнопок:
		ButtonCreateTop = false; CreateTop->BackColor = Color::Gainsboro;
		ButtonMoveTop = false; MoveTop->BackColor = Color::Gainsboro;
		ButtonCreateRoad = false; CreateRoad->BackColor = Color::Gainsboro;
		ButtonSearchRoad = false; SearchRoad->BackColor = Color::Gainsboro;
	}
	else {
		ButtonDeleteTop = false; DeleteTop->BackColor = Color::Gainsboro;
	}
	PaperBox->Invalidate(); // Перерисовка.
}

// Обработка события - Переместить вершину.
System::Void Practice22::MyForm::MoveTop_Click(System::Object^ sender, System::EventArgs^ e) {
	if (ButtonMoveTop == false) {
		ButtonMoveTop = true; MoveTop->BackColor = Color::Blue;
		SelectIndex = -1; // Номер выбранной пользователем вершины. Первоначально равен -1.

		// Отмена прочих активных кнопок:
		ButtonCreateTop = false; CreateTop->BackColor = Color::Gainsboro;
		ButtonDeleteTop = false; DeleteTop->BackColor = Color::Gainsboro;
		ButtonCreateRoad = false; CreateRoad->BackColor = Color::Gainsboro;
		ButtonSearchRoad = false; SearchRoad->BackColor = Color::Gainsboro;
	}
	else {
		ButtonMoveTop = false; MoveTop->BackColor = Color::Gainsboro;
	}
	PaperBox->Invalidate(); // Перерисовка.
}

// Обработка события - Создать дугу.
System::Void Practice22::MyForm::CreateRoad_Click(System::Object^ sender, System::EventArgs^ e) {
	if (ButtonCreateRoad == false) {
		ButtonCreateRoad = true; CreateRoad->BackColor = Color::Blue;
		SelectIndex = -1; // Номер выбранной пользователем вершины. Первоначально равен -1.

		// Отмена прочих активных кнопок:
		ButtonCreateTop = false; CreateTop->BackColor = Color::Gainsboro;
		ButtonDeleteTop = false; DeleteTop->BackColor = Color::Gainsboro;
		ButtonMoveTop = false; MoveTop->BackColor = Color::Gainsboro;
		ButtonSearchRoad = false; SearchRoad->BackColor = Color::Gainsboro;

	}
	else {
		ButtonCreateRoad = false; CreateRoad->BackColor = Color::Gainsboro;
		
	}
	PaperBox->Invalidate(); // Перерисовка.
}

// Обработка события - Поиск кратчайшего пути.
System::Void Practice22::MyForm::SearchRoad_Click(System::Object^ sender, System::EventArgs^ e) {
	if (ButtonSearchRoad == false) {
		ButtonSearchRoad = true; SearchRoad->BackColor = Color::Blue;
		ShortWay.erase(ShortWay.begin(), ShortWay.end()); // Отчиска предыдущего поиска.
		SelectIndex = -1; // Номер выбранной пользователем вершины. Первоначально равен -1.

		// Отмена прочих активных кнопок:
		ButtonCreateTop = false; CreateTop->BackColor = Color::Gainsboro;
		ButtonDeleteTop = false; DeleteTop->BackColor = Color::Gainsboro;
		ButtonMoveTop = false; MoveTop->BackColor = Color::Gainsboro;
		ButtonCreateRoad = false; CreateRoad->BackColor = Color::Gainsboro;
	}
	else {
		ButtonSearchRoad = false; SearchRoad->BackColor = Color::Gainsboro;
	}
	PaperBox->Invalidate(); // Перерисовка.
}

void warning_window() {
	String^ warningMessage = "Введите число!\n\nПожалуйста, введите положительное число и повторите попытку.";
	MessageBox::Show(warningMessage, "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
}

// Обработка события - Задать длину дуги.
System::Void Practice22::MyForm::CreateRoadLen_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		if (Convert::ToInt32(RoadLen->Text) >= 0) {
			RoadLenBox->Visible = false;
			Roads[Roads.size() - 1].LEN = Convert::ToInt32(RoadLen->Text);
		}
		else {
			warning_window();
			RoadLen->Text = "";
			RoadLen->Focus();
		}
	}
	catch (System::FormatException^ e) {
		warning_window();
		RoadLen->Text = "";
		RoadLen->Focus();
	}
	PaperBox->Invalidate(); // Перерисовка.
}

// Обработка события - Удалить все вершины.
System::Void Practice22::MyForm::DeleteAll_Click(System::Object^ sender, System::EventArgs^ e) {
	ButtonCreateTop = false; CreateTop->BackColor = Color::Gainsboro;
	ButtonDeleteTop = false; DeleteTop->BackColor = Color::Gainsboro;
	ButtonMoveTop = false; MoveTop->BackColor = Color::Gainsboro;
	ButtonCreateRoad = false; CreateRoad->BackColor = Color::Gainsboro;
	ButtonSearchRoad = false; SearchRoad->BackColor = Color::Gainsboro;
	// Надо добавить подтверждение отчистки.
	Tops.erase(Tops.begin(), Tops.end());
	Roads.erase(Roads.begin(), Roads.end());

	PaperBox->Invalidate(); // Перерисовка.
}

// Обработка события - нажатие на кнопку мыши на холсте.
System::Void Practice22::MyForm::PaperBox_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	mousePosition.X = e->Location.X; mousePosition.Y = e->Location.Y; // Сохраняем положение мыши.

	// Обработка события в режиме Создание вершины.
	if (ButtonCreateTop) {
		Tops.push_back(mousePosition);
	}

	// Обработка события в режиме Удаление вершины.
	else if (ButtonDeleteTop) {
		int MinIndex = Search();
		if (MinIndex != -1) {
			// Удаляем все связанные с данной вершиной дуги.
			for (int i = Roads.size() - 1; i >= 0; i--) {
				if (Roads[i].A == MinIndex || Roads[i].B == MinIndex) {
					Roads.erase(Roads.begin() + i);
				}
				else {
					// Умешьшаем все значения большие выбранной вершины, так как она удалится в дальнейшем, а вектор переместит последующие вершины на позицию назад.
					if (Roads[i].A >= MinIndex) Roads[i].A--;
					if (Roads[i].B >= MinIndex) Roads[i].B--;
				}
			}
			Tops.erase(Tops.begin() + MinIndex);
		}
	}

	// Обработка события в режиме Перемешение вершины.
	else if (ButtonMoveTop) {
		SelectIndex = Search();
		if (SelectIndex != -1) {
			SelectMoveTop = !SelectMoveTop;
			TempMoveTop = Tops[SelectIndex]; // Для отката назад в случае прерывания процесса перемещения.
		}
	}

	// Обработка события в режиме Создание дуги.
	else if (ButtonCreateRoad) {
		// Далее проверка на случай создания дуги в одну и ту же вершину.
		if (SelectIndex != Search()) {
			SelectIndex = Search();
			if (SelectIndex != -1) {
				if (SelectRoad == false) {
					RoadLenBox->Visible = false;
					TempRoad.A = SelectIndex;
					// Далее проверка на наличие ввода значения длинны дуги в поле.
					if (Roads.size() > 0) if (Roads[Roads.size() - 1].LEN == -1) Roads.erase(Roads.begin() + Roads.size() - 1);
				}
				else {
					RoadLenBox->Visible = true;
					TempRoad.B = SelectIndex;
					TempRoad.LEN = -1;
					SelectIndex = -1;
					Roads.push_back(TempRoad);

					// Очистка и фокус на поле для записи длины дороги.
					RoadLen->Text = "";
					RoadLen->Focus();
				}
				SelectRoad = !SelectRoad;
			}

		}
	}

	// Обработка события в режиме Поиск.
	else if (ButtonSearchRoad) {
		SelectIndex = Search();
		if (SelectIndex != -1) {
			if (SelectSearchTop == false) {
				ShortRoad.A = SelectIndex;
			}
			else {
				ShortRoad.B = SelectIndex;
				Deikstra();
				if (ShortRoad.LEN == -2) OutputLen->Text = "Нет пути от " + Convert::ToString(ShortRoad.A + 1) + " до " + Convert::ToString(ShortRoad.B + 1);
				else OutputLen->Text = "Длина кратчайшего пути\nот " + Convert::ToString(ShortRoad.A + 1) + " до " + Convert::ToString(ShortRoad.B + 1) + " = " + Convert::ToString(ShortRoad.LEN);
			}
			SelectSearchTop = !SelectSearchTop;
		}
	}

	PaperBox->Invalidate(); // Перерисовка.
}

// Обработка события - Перемещение мыши на холсте.
System::Void Practice22::MyForm::PaperBox_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	mousePosition.X = e->Location.X; mousePosition.Y = e->Location.Y; // Сохраняем положение мыши.
	if (SelectMoveTop && SelectIndex != -1) {
		Tops[SelectIndex] = mousePosition;
	}

	PaperBox->Invalidate(); // Перерисовка.
}

// Обработка события - Вход в пределы холста.
System::Void Practice22::MyForm::PaperBox_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	InsideTheFrame = true;
	if (ButtonMoveTop == false) SelectMoveTop = false;
	if (ButtonCreateRoad == false) SelectRoad = false;
	if (ButtonSearchRoad == false) SelectSearchTop = false;
	if (ButtonCreateRoad == false && Roads.size() > 0 && Roads[Roads.size() - 1].LEN == -1) {
		Roads.erase(Roads.begin() + Roads.size() - 1);
		RoadLenBox->Visible = false;
	}
	if (ButtonSearchRoad == false && SelectSearchTop == false ) OutputLen->Text = "";
}

// Обработка события - Выход за пределы поля холста.
System::Void Practice22::MyForm::PaperBox_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	InsideTheFrame = false;
	if (SelectMoveTop) Tops[SelectIndex] = TempMoveTop;

	PaperBox->Invalidate(); // Перерисовка.
}
