/*
 * Copyright (C) 2015 Open Source Robotics Foundation
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

#include <gtest/gtest.h>

#include "ignition/math/Helpers.hh"
#include "ignition/math/FrameGraph.hh"

using namespace ignition;
using namespace math;

/////////////////////////////////////////////////
TEST(FrameGraphTest, ConstructTest)
{
  FrameGraph frameGraph;

  // frameGraph comes with a built-in "world" frame
  Pose3d px1(1,0,0,0,0,0);
  frameGraph.AddFrame("x1", px1, "world");

  Pose3d px2(1,0,0,0,0,0);
  bool r = frameGraph.AddFrame("x2", px2, "x1");
  EXPECT_TRUE(r);

  Pose3d p;
  r = frameGraph.Pose("x2", "world", p);
  EXPECT_TRUE(r);

  std::cout << "POSE p: " << p << std::endl;
  EXPECT_EQ(2, p.Pos().X());

  Pose3d px = px2 + px1;
  std::cout << "POSE px: " << px << std::endl;
}

//  EXPECT_EQ(2, 42);
//  EXPECT_DOUBLE_EQ(frustum.AspectRatio(), 1.3434);


/////////////////////////////////////////////////
TEST(FrameGraphTest, Poseing)
{
  std::cout << "===== POSE TEST =====" << std::endl;
}