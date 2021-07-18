#include "SearchRow.h"

//Сравнение зарплат
bool SearchRow::compareSal(Nullable<Decimal> v_sal)
{

  if (sal == "" || sal == nullptr) return false;

  Decimal values_sal = Convert::ToDecimal(v_sal), search_sal = Convert::ToDecimal(sal, Globalization::CultureInfo::InstalledUICulture);

  if (Decimal::Compare(search_sal, values_sal) > 0)  return true;
  else return false;
}

//Сравнение стажа
bool SearchRow::compareExp(Nullable<int> v_exp)
{
	if (exp == "" || exp == nullptr) return false;

	int values_exp = Convert::ToInt32(v_exp), search_exp = Convert::ToInt32(exp, Globalization::CultureInfo::InstalledUICulture);

	if ( search_exp < values_exp)  return true;
	else return false;
}
