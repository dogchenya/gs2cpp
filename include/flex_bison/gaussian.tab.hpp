/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_GAUSSIAN_TAB_HPP_INCLUDED
# define YY_YY_GAUSSIAN_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    GAUSSIAN_VOID = 258,
    GAUSSIAN_STRUCT = 259,
    GAUSSIAN_ROS_PARAMS = 260,
    GAUSSIAN_BOOL = 261,
    GAUSSIAN_BYTE = 262,
    GAUSSIAN_SHORT = 263,
    GAUSSIAN_INT = 264,
    GAUSSIAN_DOUBLE = 265,
    GAUSSIAN_FLOAT = 266,
    GAUSSIAN_LONG = 267,
    GAUSSIAN_STRING = 268,
    GAUSSIAN_VECTOR = 269,
    GAUSSIAN_MAP = 270,
    GAUSSIAN_NAMESPACE = 271,
    GAUSSIAN_ROS_NAMESPACE = 272,
    GAUSSIAN_INTERFACE = 273,
    GAUSSIAN_IDENTIFIER = 274,
    GAUSSIAN_OUT = 275,
    GAUSSIAN_OP = 276,
    GAUSSIAN_KEY = 277,
    GAUSSIAN_ROUTE_KEY = 278,
    GAUSSIAN_REQUIRE = 279,
    GAUSSIAN_OPTIONAL = 280,
    GAUSSIAN_CONST_INTEGER = 281,
    GAUSSIAN_CONST_FLOAT = 282,
    GAUSSIAN_FALSE = 283,
    GAUSSIAN_TRUE = 284,
    GAUSSIAN_STRING_LITERAL = 285,
    GAUSSIAN_SCOPE_DELIMITER = 286,
    GAUSSIAN_CONST = 287,
    GAUSSIAN_ENUM = 288,
    GAUSSIAN_UNSIGNED = 289,
    BAD_CHAR = 290
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GAUSSIAN_TAB_HPP_INCLUDED  */
