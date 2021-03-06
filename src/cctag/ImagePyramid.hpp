/*
 * Copyright 2016, Simula Research Laboratory
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef _CCTAG_IMAGEPYRAMID_HPP
#define	_CCTAG_IMAGEPYRAMID_HPP

#include "cctag/Level.hpp"

#include <opencv2/opencv.hpp>

#include <stdint.h>
#include <cstddef>
#include <vector>

namespace cctag {

class Parameters; // forward declaration

class ImagePyramid
{
public:
  ImagePyramid();
  
  ImagePyramid( const std::size_t width, const std::size_t height, const std::size_t nLevels, bool cuda_allocates );
  
  ~ImagePyramid();

  Level* getLevel( const std::size_t level ) const;
  
  std::size_t getNbLevels() const;
  
    /* The pyramid building function is never called if CUDA is used.
     */
  void build(const cv::Mat & src, const float thrLowCanny, const float thrHighCanny, const cctag::Parameters* params );

private:
  std::vector<Level*> _levels;
};

void sIntToUchar(const cv::Mat & src, cv::Mat & dst);

}

#endif	/* _CCTAG_IMAGEPYRAMID_HPP */

