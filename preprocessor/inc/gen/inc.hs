boomLine x = "#define INC_BOOM_" ++ (show x) ++ "\t"
             ++ (show $ x + 1)

main = do
  let ls = map boomLine $ [0 .. BOOM_LIMIT]
  mapM_ putStrLn ls
