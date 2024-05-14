\name{NEWS}
\title{News for Package \pkg{RApiSerialize}}
\newcommand{\ghpr}{\href{https://github.com/eddelbuettel/rapiserialize/pull/#1}{##1}}
\newcommand{\ghit}{\href{https://github.com/eddelbuettel/rapiserialize/issues/#1}{##1}}
\newcommand{\cpkg}{\href{http://CRAN.R-project.org/package=#1}{\pkg{#1}}}

\section{Changes in version 0.1.3 (2024-05-13)}{
  \itemize{
    \item Add an \code{xdr} argument to disable XDR for an approx.
    threefold speed increase (Travers Ching and Dirk in \ghpr{6})
    \item Use R_NO_REMAP and Rf_* prefix for API calls
    \item Minor continuous integration updates
  }
}

\section{Changes in version 0.1.2 (2022-08-25)}{
  \itemize{
    \item Correct an \code{error()} call (when missing long vector
    support) to not use i18n macro
  }
}

\section{Changes in version 0.1.1 (2022-08-07)}{
  \itemize{
    \item Updated CI use to \href{https://eddelbuettel.github.io/r-ci/}{r-ci}
    \item Expanded and updated both DESCRIPTION and README.md
    \item Updated package internals to register compiled functions
    \item Add support for serialization format 3, default remains 2
    \item Minor synchronization with upstream
  }
}

\section{Changes in version 0.1.0 (2014-04-19)}{
  \itemize{
    \item Initial public version and CRAN upload
    \item Two simple functions \code{serializeToRaw} and
      \code{unserializeFromRaw} are provided in this version; each takes
      a \code{SEXP} argument and returns a \code{SEXP} argument
  } 
}
