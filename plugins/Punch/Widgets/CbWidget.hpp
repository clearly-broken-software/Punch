/*
 * Copyright (C) 2018-2019 Rob van den Berg <rghvdberg at gmail dot org>
 *
 * This file is part of Punch
 *
 * Punch is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Punch is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Punch.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef CBWIDGET_HPP_INCLUDED
#define CBWIDGET_HPP_INCLUDED

#include "Widget.hpp"
#include "NanoVG.hpp"

START_NAMESPACE_DISTRHO

class CbWidget : public NanoWidget
{
public:
  CbWidget(Window &parent) noexcept;
  CbWidget(Widget *widget) noexcept;
  CbWidget **ptrHasMouse;
  void setPtrHasMouse(CbWidget **ptr);
  float getValue() const;
  void setValue(float value);
  void setRange(float min, float max);

protected:
  float fValue;
  float fMin;
  float fMax;

private:
  DISTRHO_LEAK_DETECTOR(CbWidget)
};

END_NAMESPACE_DISTRHO
#endif