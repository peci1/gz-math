/*
 * Copyright (C) 2012-2014 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#ifndef _IGNITION_BOX_HH_
#define _IGNITION_BOX_HH_

#include <iostream>
#include <ignition/math/Helpers.hh>
#include <ignition/math/Vector3.hh>

namespace ignition
{
  namespace math
  {
    // Forward declaration of private data
    class BoxPrivate;

    /// \class Box Box.hh ignition/math/Box.hh
    /// \brief Mathematical representation of a box and related functions.
    class IGNITION_VISIBLE Box
    {
      /// \brief Default constructor
      public: Box();

      /// \brief Constructor. This constructor will compute the box's
      /// minimum and maximum corners based on the two arguments.
      /// \param[in] _vec1 One corner of the box
      /// \param[in] _vec2 Another corner of the box
      public: Box(const Vector3d &_vec1, const Vector3d &_vec2);

      /// \brief Constructor. This constructor will compute the box's
      /// minimum and maximum corners based on the arguments.
      /// \param[in] _vec1X One corner's X position
      /// \param[in] _vec1Y One corner's Y position
      /// \param[in] _vec1Z One corner's Z position
      /// \param[in] _vec2X Other corner's X position
      /// \param[in] _vec2Y Other corner's Y position
      /// \param[in] _vec2Z Other corner's Z position
      public: Box(double _vec1X, double _vec1Y, double _vec1Z,
                  double _vec2X, double _vec2Y, double _vec2Z);

      /// \brief Copy Constructor
      /// \param[in]  _b Box to copy
      public: Box(const Box &_b);

      /// \brief Destructor
      public: virtual ~Box();

      /// \brief Get the length along the x dimension
      /// \return Double value of the length in the x dimension
      public: double XLength() const;

      /// \brief Get the length along the y dimension
      /// \return Double value of the length in the y dimension
      public: double YLength() const;

      /// \brief Get the length along the z dimension
      /// \return Double value of the length in the z dimension
      public: double ZLength() const;

      /// \brief Get the size of the box
      /// \return Size of the box
      public: math::Vector3d Size() const;

      /// \brief Get the box center
      /// \return The center position of the box
      public: math::Vector3d Center() const;

      /// \brief Merge a box with this box
      /// \param[in]  _box Box to add to this box
      public: void Merge(const Box &_box);

      /// \brief Assignment operator. Set this box to the parameter
      /// \param[in]  _b Box to copy
      /// \return The new box.
      public: Box &operator=(const Box &_b);

      /// \brief Addition operator. result = this + _b
      /// \param[in] _b Box to add
      /// \return The new box
      public: Box operator+(const Box &_b) const;

      /// \brief Addition set operator. this = this + _b
      /// \param[in] _b Box to add
      /// \return This new box
      public: const Box &operator+=(const Box &_b);

      /// \brief Equality test operatoer
      /// \param[in] _b Box to test
      /// \return True if equal
      public: bool operator==(const Box &_b) const;

      /// \brief Inequality test operatoer
      /// \param[in] _b Box to test
      /// \return True if not equal
      public: bool operator!=(const Box &_b) const;

      /// \brief Subtract a vector from the min and max values
      /// \param _v The vector to use during subtraction
      /// \return The new box
      public: Box operator-(const Vector3d &_v);

      /// \brief Output operator
      /// \param[in] _out Output stream
      /// \param[in] _b Box to output to the stream
      /// \return The stream
      public: friend std::ostream &operator<<(std::ostream &_out,
                                              const ignition::math::Box &_b);

      /// \brief Get the minimum corner.
      /// \return The Vector3d that is the minimum corner of the box.
      public: const Vector3d &Min() const;

      /// \brief Get the maximum corner.
      /// \return The Vector3d that is the maximum corner of the box.
      public: const Vector3d &Max() const;

      /// \brief Get a mutable version of the minimum corner.
      /// \return The Vector3d that is the minimum corner of the box.
      public: Vector3d &Min();

      /// \brief Get a mutable version of the maximum corner.
      /// \return The Vector3d that is the maximum corner of the box.
      public: Vector3d &Max();

      /// \brief Test box intersection. This test will only work if
      /// both box's minimum corner is less than or equal to their
      /// maximum corner.
      /// \param[in] _box Box to check for intersection with this box.
      /// \return True if this box intersects _box.
      public: bool Intersects(const Box &_box) const;

      /// \brief Private data pointer
      private: BoxPrivate *dataPtr;
    };
  }
}
#endif