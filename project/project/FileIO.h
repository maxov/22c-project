/**
 * Defines the FileIO class.
 * By MOKT (Max Ovsiankin, Ori Klein, Keivan Safavi, Tomer Erlich)
 */
#ifndef __FILE_IO_H
#define __FILE_IO_H

#include <string>
#include <vector>

#include "Food.h"

using std::string;

/**
 * Handles file operations related to food.
 *
 * File format for food:
 * <isIngredient> <id> "<name>" <rest...>
 * for ingredients, <rest...> = "<foodGroup>" <calories> <fat> <protein> <fiber>
 * <sugar> <carbs>
 * for recipes, <rest...> = <ingredient1> <ingredient2> <ingredient3>...
 */
class FileIO {
  /**
   * The message printed when file IO fails.
   */
  const static string failMsg;

 public:
  /**
   * Save the given vector of food into the given file as a string.
   * Returns true if the operation was successful, and false otherwise.
   */
  bool save(string file, vector<Food> *food);

  /**
   * Load a vector of food from the given file as a string.
   */
  vector<Food> *load(string file);
};

#endif
