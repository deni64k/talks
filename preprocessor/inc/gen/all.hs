import System.Environment (getArgs)

boomLine fname = "#include \"" ++ fname ++ "\""

main = do
  filesIn <- getArgs
  mapM_ putStrLn $ map boomLine filesIn
