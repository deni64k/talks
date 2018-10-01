boomLine x = "#define DEC_BOOM_" ++ (show $ x + 1) ++ "\t"
             ++ (show x)

main = do
  let ls = map boomLine $ [0 .. BOOM_LIMIT]
  mapM_ putStrLn ls
