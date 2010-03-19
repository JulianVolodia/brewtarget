/*
 * unit.h is part of Brewtarget, and is Copyright Philip G. Lee
 * (rocketman768@gmail.com), 2009.
 *
 * Brewtarget is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * Brewtarget is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _UNIT_H
#define _UNIT_H

class Unit;
class Units; // A container of instances.
class KilogramUnit;
class GramUnit;
class MilligramUnit;
class PoundUnit;
class OunceUnit;
class LiterUnit;
class MilliliterUnit;
class USGallonUnit;
class USQuartUnit;
class USCupUnit;
class ImperialGallonUnit;
class ImperialQuartUnit;
class ImperialCupUnit;
class TablespoonUnit;
class TeaspoonUnit;
class SecondUnit;
class MinuteUnit;
class HourUnit;
class CelsiusUnit;
class FahrenheitUnit;
class KelvinUnit;

#include <QString>
#include <string>
#include <map>
#include <QMultiMap>

enum UnitType
{
   Mass,
   Volume,
   Time,
   Temp
};

enum iUnitSystem
{
    SI,
    USCustomary,
    Imperial,
    ImperialAndUS,
    Any
};

enum TempScale
{
    Celsius,
    Fahrenheit,
    Kelvin
};

inline QString unitSystemToString(iUnitSystem us)
{
   switch (us)
   {
      case SI: return "SI";
      case USCustomary: return "USCustomary";
      case Imperial: return "Imperial";
      default: return 0;
   }
}

inline QString tempScaleToString(TempScale ts)
{
   switch (ts)
   {
      case Celsius: return "Celsius";
      case Fahrenheit: return "Fahrenheit";
      default: return 0;
   }
}
// TODO: implement ppm, percent, diastatic power, ibuGalPerLb, gravity, srm, volumes.

class Unit
{
   public:
      // Seems these can't be PURE virtuals b/c of some issue with std::map.
      virtual double toSI( double amt ) const { return amt; };
      virtual double fromSI( double amt ) const { return amt; };
      // The unit name will be the singular of the commonly used abbreviation.
      virtual const QString& getUnitName() const { return 0; };
      virtual const QString& getSIUnitName() const { return 0; };

      virtual const int getUnitType() const { return 0; };
      virtual const int getUnitOrTempSystem() const { return 0; };

      static double convert( double amount, QString& fromUnit, QString& toUnit );
      static QString convert( QString qstr, QString toUnit );
      static double qstringToSI( QString qstr );

   private:
      static Unit* getUnit(QString& name, bool matchCurrentSystem = true);

      static QMultiMap<QString, Unit*> nameToUnit;
      static bool isMapSetup;
      static void setupMap();
};

// ================ Weight/Mass ================
class KilogramUnit : public Unit
{
   public:
      KilogramUnit();

      // Inherited methods.
      double toSI( double amt ) const;
      double fromSI( double amt ) const;
      const QString& getUnitName() const { return unitName; }
      const QString& getSIUnitName() const { return SIUnitName; }
      const int getUnitType() const { return Mass; };
      const int getUnitOrTempSystem() const { return SI; };

   private:
      QString unitName;
      QString SIUnitName;
};

class GramUnit : public Unit
{
   public:
      GramUnit();

      // Inherited methods.
      double toSI( double amt ) const;
      double fromSI( double amt ) const;
      const QString& getUnitName() const { return unitName; }
      const QString& getSIUnitName() const { return SIUnitName; }
      const int getUnitType() const { return Mass; };
      const int getUnitOrTempSystem() const { return SI; };

   private:
      QString unitName;
      QString SIUnitName;
};

class MilligramUnit : public Unit
{
   public:
      MilligramUnit();

      // Inherited methods.
      double toSI( double amt ) const;
      double fromSI( double amt ) const;
      const QString& getUnitName() const { return unitName; }
      const QString& getSIUnitName() const { return SIUnitName; }
      const int getUnitType() const { return Mass; };
      const int getUnitOrTempSystem() const { return SI; };

   private:
      QString unitName;
      QString SIUnitName;
};

class PoundUnit : public Unit
{
   public:
      PoundUnit();
      
      // Inherited methods.
      double toSI( double amt ) const;
      double fromSI( double amt ) const;
      const QString& getUnitName() const { return unitName; }
      const QString& getSIUnitName() const { return SIUnitName; }
      const int getUnitType() const { return Mass; };
      const int getUnitOrTempSystem() const { return ImperialAndUS; };
      
   private:
      QString unitName;
      QString SIUnitName;
};

class OunceUnit : public Unit
{
   public:
      OunceUnit();

      // Inherited methods.
      double toSI( double amt ) const;
      double fromSI( double amt ) const;
      const QString& getUnitName() const { return unitName; }
      const QString& getSIUnitName() const { return SIUnitName; }
      const int getUnitType() const { return Mass; };
      const int getUnitOrTempSystem() const { return ImperialAndUS; };

   private:
      QString unitName;
      QString SIUnitName;
};

// ================ Volume ================
class LiterUnit : public Unit
{
   public:
      LiterUnit();

      // Inherited methods.
      double toSI( double amt ) const;
      double fromSI( double amt ) const;
      const QString& getUnitName() const { return unitName; }
      const QString& getSIUnitName() const { return SIUnitName; }
      const int getUnitType() const { return Volume; };
      const int getUnitOrTempSystem() const { return SI; };

   private:
      QString unitName;
      QString SIUnitName;
};

class MilliliterUnit : public Unit
{
   public:
      MilliliterUnit();

      // Inherited methods.
      double toSI( double amt ) const;
      double fromSI( double amt ) const;
      const QString& getUnitName() const { return unitName; }
      const QString& getSIUnitName() const { return SIUnitName; }
      const int getUnitType() const { return Volume; };
      const int getUnitOrTempSystem() const { return SI; };

   private:
      QString unitName;
      QString SIUnitName;
};

class USGallonUnit : public Unit
{
   public:
      USGallonUnit();

      // Inherited methods.
      double toSI( double amt ) const;
      double fromSI( double amt ) const;
      const QString& getUnitName() const { return unitName; }
      const QString& getSIUnitName() const { return SIUnitName; }
      const int getUnitType() const { return Volume; };
      const int getUnitOrTempSystem() const { return USCustomary; };

   private:
      QString unitName;
      QString SIUnitName;
};

class USQuartUnit : public Unit
{
   public:
      USQuartUnit();

      // Inherited methods.
      double toSI( double amt ) const;
      double fromSI( double amt ) const;
      const QString& getUnitName() const { return unitName; }
      const QString& getSIUnitName() const { return SIUnitName; }
      const int getUnitType() const { return Volume; };
      const int getUnitOrTempSystem() const { return USCustomary; };

   private:
      QString unitName;
      QString SIUnitName;
};

class USCupUnit : public Unit
{
   public:
      USCupUnit();

      // Inherited methods.
      double toSI( double amt ) const;
      double fromSI( double amt ) const;
      const QString& getUnitName() const { return unitName; }
      const QString& getSIUnitName() const { return SIUnitName; }
      const int getUnitType() const { return Volume; };
      const int getUnitOrTempSystem() const { return USCustomary; };

   private:
      QString unitName;
      QString SIUnitName;
};

class ImperialGallonUnit : public Unit
{
   public:
      ImperialGallonUnit();

      // Inherited methods.
      double toSI( double amt ) const;
      double fromSI( double amt ) const;
      const QString& getUnitName() const { return unitName; }
      const QString& getSIUnitName() const { return SIUnitName; }
      const int getUnitType() const { return Volume; };
      const int getUnitOrTempSystem() const { return Imperial; };

   private:
      QString unitName;
      QString SIUnitName;
};

class ImperialQuartUnit : public Unit
{
   public:
      ImperialQuartUnit();

      // Inherited methods.
      double toSI( double amt ) const;
      double fromSI( double amt ) const;
      const QString& getUnitName() const { return unitName; }
      const QString& getSIUnitName() const { return SIUnitName; }
      const int getUnitType() const { return Volume; };
      const int getUnitOrTempSystem() const { return Imperial; };

   private:
      QString unitName;
      QString SIUnitName;
};

class ImperialCupUnit : public Unit
{
   public:
      ImperialCupUnit();

      // Inherited methods.
      double toSI( double amt ) const;
      double fromSI( double amt ) const;
      const QString& getUnitName() const { return unitName; }
      const QString& getSIUnitName() const { return SIUnitName; }
      const int getUnitType() const { return Volume; };
      const int getUnitOrTempSystem() const { return Imperial; };

   private:
      QString unitName;
      QString SIUnitName;
};

class ImperialTablespoonUnit : public Unit
{
   public:
      ImperialTablespoonUnit();

      // Inherited methods.
      double toSI( double amt ) const;
      double fromSI( double amt ) const;
      const QString& getUnitName() const { return unitName; }
      const QString& getSIUnitName() const { return SIUnitName; }
      const int getUnitType() const { return Volume; };
      const int getUnitOrTempSystem() const { return Imperial; };

   private:
      QString unitName;
      QString SIUnitName;
};

class ImperialTeaspoonUnit : public Unit
{
   public:
      ImperialTeaspoonUnit();

      // Inherited methods.
      double toSI( double amt ) const;
      double fromSI( double amt ) const;
      const QString& getUnitName() const { return unitName; }
      const QString& getSIUnitName() const { return SIUnitName; }
      const int getUnitType() const { return Volume; };
      const int getUnitOrTempSystem() const { return Imperial; };

   private:
      QString unitName;
      QString SIUnitName;
};

class USTablespoonUnit : public Unit
{
   public:
      USTablespoonUnit();

      // Inherited methods.
      double toSI( double amt ) const;
      double fromSI( double amt ) const;
      const QString& getUnitName() const { return unitName; }
      const QString& getSIUnitName() const { return SIUnitName; }
      const int getUnitType() const { return Volume; };
      const int getUnitOrTempSystem() const { return USCustomary; };

   private:
      QString unitName;
      QString SIUnitName;
};

class USTeaspoonUnit : public Unit
{
   public:
      USTeaspoonUnit();

      // Inherited methods.
      double toSI( double amt ) const;
      double fromSI( double amt ) const;
      const QString& getUnitName() const { return unitName; }
      const QString& getSIUnitName() const { return SIUnitName; }
      const int getUnitType() const { return Volume; };
      const int getUnitOrTempSystem() const { return USCustomary; };

   private:
      QString unitName;
      QString SIUnitName;
};

// ================ Time ================
class SecondUnit : public Unit
{
   public:
      SecondUnit();

      // Inherited methods.
      double toSI( double amt ) const;
      double fromSI( double amt ) const;
      const QString& getUnitName() const { return unitName; }
      const QString& getSIUnitName() const { return SIUnitName; }
      const int getUnitType() const { return Time; };
      const int getUnitOrTempSystem() const { return Any; };

   private:
      QString unitName;
      QString SIUnitName;
};

class MinuteUnit : public Unit
{
   public:
      MinuteUnit();
      
      // Inherited methods.
      double toSI( double amt ) const;
      double fromSI( double amt ) const;
      const QString& getUnitName() const { return unitName; }
      const QString& getSIUnitName() const { return SIUnitName; }
      const int getUnitType() const { return Time; };
      const int getUnitOrTempSystem() const { return Any; };
      
   private:
      QString unitName;
      QString SIUnitName;
};

class HourUnit : public Unit
{
   public:
      HourUnit();

      // Inherited methods.
      double toSI( double amt ) const;
      double fromSI( double amt ) const;
      const QString& getUnitName() const { return unitName; }
      const QString& getSIUnitName() const { return SIUnitName; }
      const int getUnitType() const { return Time; };
      const int getUnitOrTempSystem() const { return Any; };

   private:
      QString unitName;
      QString SIUnitName;
};

// ================ Temperature ================

class CelsiusUnit : public Unit
{
   public:
      CelsiusUnit();

      // Inherited methods.
      double toSI( double amt ) const;
      double fromSI( double amt ) const;
      const QString& getUnitName() const { return unitName; }
      const QString& getSIUnitName() const { return SIUnitName; }
      const int getUnitType() const { return Temp; };
      const int getUnitOrTempSystem() const { return Celsius; };

   private:
      QString unitName;
      QString SIUnitName;
};

class KelvinUnit : public Unit
{
   public:
      KelvinUnit();

      // Inherited methods.
      double toSI( double amt ) const;
      double fromSI( double amt ) const;
      const QString& getUnitName() const { return unitName; }
      const QString& getSIUnitName() const { return SIUnitName; }
      const int getUnitType() const { return Temp; };
      const int getUnitOrTempSystem() const { return Kelvin; };

   private:
      QString unitName;
      QString SIUnitName;
};

class FahrenheitUnit : public Unit
{
   public:
      FahrenheitUnit();

      // Inherited methods.
      double toSI( double amt ) const;
      double fromSI( double amt ) const;
      const QString& getUnitName() const { return unitName; }
      const QString& getSIUnitName() const { return SIUnitName; }
      const int getUnitType() const { return Temp; };
      const int getUnitOrTempSystem() const { return Fahrenheit; };

   private:
      QString unitName;
      QString SIUnitName;
};

class Units
{
public:
   Units();

   // === Mass ===
   static KilogramUnit *kilograms;
   static GramUnit *grams;
   static MilligramUnit *milligrams;
   static PoundUnit *pounds;
   static OunceUnit *ounces;
   // === Volume ===
   static LiterUnit *liters;
   static MilliliterUnit *milliliters;
   static USGallonUnit *us_gallons;
   static USQuartUnit *us_quarts;
   static USCupUnit *us_cups;
   static ImperialGallonUnit *imperial_gallons;
   static ImperialQuartUnit *imperial_quarts;
   static ImperialCupUnit *imperial_cups;
   static USTablespoonUnit *us_tablespoons;
   static USTeaspoonUnit *us_teaspoons;
   static ImperialTablespoonUnit *imperial_tablespoons;
   static ImperialTeaspoonUnit *imperial_teaspoons;
   // === Time ===
   static SecondUnit *seconds;
   static MinuteUnit *minutes;
   static HourUnit *hours;
   // === Temperature ===
   static CelsiusUnit *celsius;
   static FahrenheitUnit *fahrenheit;
   static KelvinUnit *kelvin;
};

#endif // _UNIT_H
